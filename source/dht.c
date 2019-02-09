#include "dht.h"

//0, 1 -> humidity
//2, 3 -> temperature
//4 -> check sum
int dht11_val[5];

//save data temperature, humidity
float t, h;

int read_dht_val(void)
{

	int i;
	int counter = 0;
	int laststate = 1, j=0;

	//wiringPi setup
	int wiringPi = wiringPiSetup();

	//initialize global variable
	for(i=0; i<5; i++){
		dht11_val[i]=0;
	}

	//set pin(7) mode to OUTPUT for send signal to dht sensor
	pinMode(DHT11PIN, OUTPUT);

	//write the value(LOW = 0) to the given pin(7)
    digitalWrite(DHT11PIN, LOW);
    delay(18);

	//write the value(HIGH = 1) to the given pin(7)
    digitalWrite(DHT11PIN, HIGH);
    delayMicroseconds(40);
 
	//set pin mode to INPUT for get data from dht sensor
    pinMode(DHT11PIN, INPUT);

	//get data while MAX_TIME(83)
	for(i=0; i<MAX_TIME; i++)
	{
		counter=0;
		//read signal from pin, check the length of signal(1,0)
		while(digitalRead(DHT11PIN) == laststate){
			//counter mean signal length (us)
			counter++;
			delayMicroseconds(1);
			if(counter==255)
				break;
		}
		if(counter==255) break;
		//change last state (1,0)
		laststate = 1-laststate;
		// first data (=when fist call this function) from dht sensor is error 
		// because first data come early, if i want get first data
		// change i>=4  to  i>=2 (only first time)
		if((i>=4) && (i%2 == 0)) {
			//dht11 sensor data come linear
			//shift data
			dht11_val[j/8] <<= 1;
			
			//if signal length > 30 that mean signal value = 1
			//else value = 0
			if(counter > 30)
				dht11_val[j/8]|=1;
			j++;
		}		
	}
	//get temperature , humidity
	t = (dht11_val[2]+dht11_val[3]/10.);
	h = (dht11_val[0]+dht11_val[1]/10.);


	//calculate checksum
	if((j>=40) && (dht11_val[4] == ((dht11_val[0] + dht11_val[1] + dht11_val[2] + dht11_val[3]) & 0xFF)))
	{
		//if temperature, humidity is 0 -> error
		if((dht11_val[0] == 0) && (dht11_val[2]==0))
			return 0;

		//checksum good
		printf("temp=%lf*c, humidity=%lf\%\n", t, h);
		return 1;
	}

	//if checksum error
	return 0;
}
