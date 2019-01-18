#include "pms.h"

int incomingByte = 0; // for incoming serial data

unsigned char pms[32];
int PM1_0, PM2_5, PM10;
int fd;

int open_pms(){
	if((fd = serialOpen("/dev/ttyAMA0", 9600)) <0)
	{
		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
 		return 0 ;
  	}
	printf("Open PMS Sensor - Uart Serial Connection...\n");
	delay(1000);
	return 1;
}

int read_pms(){
	int i=0, chksum=0;

	pms[0]=0x42;
	pms[1]=0x4d;
	chksum=0;	
	while(serialDataAvail(fd) >= 32){
		if(serialGetchar(fd)!=0x42)
			continue;
		if(serialGetchar(fd)!=0x4d)
			continue;
		for(i=2; i<32; i++){
			pms[i]=serialGetchar(fd);
		}
		PM1_0=(pms[10]<<8) | pms[11];
		PM2_5=(pms[12]<<8) | pms[13];
		PM10=(pms[14]<<8) | pms[15];
		for(i=0; i<30; i++)
			chksum+=pms[i];

		if(((pms[30]<<8)|pms[31])!= chksum){
			printf("wrong data, chksum = %d, %d\n", (pms[30]<<8) | pms[31], chksum);
			return 0;
		}
			
		printf("correct data\n");
		printf("PM1.0: %d, PM2.5: %d, PM10: %d\n", PM1_0, PM2_5, PM10);
		return 1;
	}
	return 0;
}

int close_pms() {	
	serialClose(fd);
	return 1;
}
