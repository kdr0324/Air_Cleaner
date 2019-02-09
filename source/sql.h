#ifndef _sql_h
#define _sql_h

#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//MYSQL DB Login information
#define DB_HOST "127.0.0.1"
#define DB_USER "drkim"
#define DB_PASS "qwe123!@#"
#define DB_NAME "test"
#define CHOP(x) x[strlen(x)-1] = ' '

MYSQL * conn;
MYSQL_RES * result;
MYSQL_ROW row;

//connect_sql to mysql db 
int connect_sql();
//disconnect db server
int disconnect_sql();
//insert query (room air condition, temperature, humidity, PM1_0, PM2_5, PM10)
int insert_query(float temperature, float humidity, float pm1_0, float pm2_5, float pm10);
void finish_with_error();


#endif //_sql_h
