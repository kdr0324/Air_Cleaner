#include "dht.h"

//int dht11_val[5] = {0,0,0,0,0};
//float t, h;

int read_dht_val(void)
{

	int i;
	int counter = 0;
	int laststate = 1, j=0;

	int wiringPi = wiringPiSetup();

	pinMode(DHT11PIN, OUTPUT);
       	digitalWrite(DHT11PIN, LOW);
       	delay(18);
       	digitalWrite(DHT11PIN, HIGH);
       	delayMicroseconds(40);
       	pinMode(DHT11PIN, INPUT);

	for(i=0; i<MAX_TIME; i++)
	{
		counter=0;
		while(digitalRead(DHT11PIN) == laststate){
			counter++;
			delayMicroseconds(1);
			if(counter==255)
				break;
		}
		if(counter==255) break;
		laststate = 1-laststate;
		if((i>=2) && (i%2 == 0)) {
			dht11_val[j/8] <<= 1;
			if(counter > 30)
				dht11_val[j/8]|=1;
			j++;
		}		
	}
	t = (dht11_val[2]+dht11_val[3]/10.);
	h = (dht11_val[0]+dht11_val[1]/10.);



	if((j>=40) && (dht11_val[4] == ((dht11_val[0] + dht11_val[1] + dht11_val[2] + dht11_val[3]) & 0xFF)))
	{
		if((dht11_val[0] == 0) && (dht11_val[2]==0))
			return 0;

		//printf("temp=%lf*c, humidity=%lf\%\n", t, h);
		return 1;
	}

	return 0;
}
