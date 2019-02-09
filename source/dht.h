#ifndef _dht_h_
#define _dht_h_

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//read time for dht sensor
#define MAX_TIME 83

//connected gpio pin num
#define DHT11PIN 7

//global variable in dht.c
//0, 1 -> humidity
//2, 3 -> temperature
//4 -> check sum
extern int dht11_val[5];

//save data temperature, humidity
extern float t, h;

//read dht sensor function
int read_dht_val(void);




#endif //_dht_h_
