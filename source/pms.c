#include "pms.h"

int incomingByte = 0; // for incoming serial data

unsigned char pms[32];
int PM1_0, PM2_5, PM10;
int fd;

//UART serial connect
int open_pms(){
	//UART serial device Open "/dev/ttyAMA0", 9600
	if((fd = serialOpen("/dev/ttyAMA0", 9600)) <0)
	{
		//error handling
		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
 		return 0 ;
  	}
	//Open PMS Sensor Success Log
	printf("Open PMS Sensor - Uart Serial Connection...\n");
	delay(1000);
	return 1;
}

//Read Data from PMS Sensor
int read_pms(){
	int i=0, chksum=0;

	//fixed data (*PMS 7003 data sheet)
	pms[0]=0x42;
	pms[1]=0x4d;
	chksum=0;	

	//while can read 32byte data from Uart Serial
	while(serialDataAvail(fd) >= 32){
		//first data = 0x42 (fixed)
		if(serialGetchar(fd)!=0x42)
			continue;
		//second data = 0x4d (fixed)
		if(serialGetchar(fd)!=0x4d)
			continue;
		//read data
		for(i=2; i<32; i++){
			pms[i]=serialGetchar(fd);
		}
		//calculate pms value from read data
		//make 2byte data
		PM1_0=(pms[10]<<8) | pms[11];
		PM2_5=(pms[12]<<8) | pms[13];
		PM10=(pms[14]<<8) | pms[15];

		//calculate chksum
		for(i=0; i<30; i++)
			chksum+=pms[i];

		//fflush Uart serial data
		serialFlush(fd);

		//check checksum
		if(((pms[30]<<8)|pms[31])!= chksum){
			//error handling return 0
			printf("wrong data, chksum = %d, %d\n", (pms[30]<<8) | pms[31], chksum);
			return 0;
		}
		
		//success receive return 1
		printf("correct data\n");
		printf("PM1.0: %d, PM2.5: %d, PM10: %d\n", PM1_0, PM2_5, PM10);
		return 1;
	}
	return 0;
}

//disconnect UART Serial
int close_pms() {	
	serialClose(fd);
	return 1;
}
