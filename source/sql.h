#ifndef _sql_h
#define _sql_h

#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define DB_HOST "127.0.0.1"
#define DB_USER "drkim"
#define DB_PASS "qwe123!@#"
#define DB_NAME "test"
#define CHOP(x) x[strlen(x)-1] = ' '

MYSQL * conn;
MYSQL_RES * result;
MYSQL_ROW row;

int connect_sql();
int disconnect_sql();
int insert_query(float temperature, float humidity, float pm1_0, float pm2_5, float pm10);
void finish_with_error();


#endif //_sql_h
