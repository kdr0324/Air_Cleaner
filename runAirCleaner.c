#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <stdlib.h>

const int pinNum=29;

int main(int argc, char* argv[]){

	// TO DO : check isrun?
	wiringPiSetup();

	if(argc == 1) return 0;

	if(!strcmp(argv[1], "start")){
		printf("Air Cleaner start..\n");
		pinMode(pinNum, OUTPUT);
		digitalWrite(pinNum, HIGH);

	}
	else if(!strcmp(argv[1], "stop")){
		printf("Air Cleaner stop..\n");
		digitalWrite(pinNum, LOW);
		pinMode(pinNum, INPUT);

	}
	else if(!strcmp(argv[1], "status")){

	}
	return 1;
}
