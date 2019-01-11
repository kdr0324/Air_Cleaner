#ifndef _dht_h_
#define _dht_h_

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_TIME 83
#define DHT11PIN 7

extern int dht11_val[5];
extern float t, h;

int read_dht_val(void);




#endif //_dht_h_
