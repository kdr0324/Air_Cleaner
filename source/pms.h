#ifndef _pms_h_
#define _pms_h_

//global variable in pms.c
extern unsigned char pms[32];
extern int PM1_0, PM2_5, PM10;

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

//open pms sensor for UART Seiral connect
int open_pms();

//read data from pms sensor
int read_pms();

//close pms sensor for UART Seiral disconnect
int close_pms();

//struct for get data from pms sensor
typedef struct {
    char     deviceType[32];
    uint8_t  frameHeader[2];
    uint16_t frameLen;
    uint16_t concPM1_0_CF1;
    uint16_t concPM2_5_CF1;
    uint16_t concPM10_0_CF1;
    uint16_t concPM1_0_amb;
    uint16_t concPM2_5_amb;
    uint16_t concPM10_0_amb;
    uint16_t rawGt0_3um;
    uint16_t rawGt0_5um;
    uint16_t rawGt1_0um;
    uint16_t rawGt2_5um;
    uint16_t rawGt5_0um;
    uint16_t rawGt10_0um;
    uint8_t  version;
    uint8_t  errorCode;
    uint16_t checksum;
    bool     dataGood;
    uint32_t readCount;

} PMS7003_framestruct;



	




#endif //_pms_h_
