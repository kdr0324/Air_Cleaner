#include "sql.h"

int connect_sql(){
	conn=mysql_init(NULL);
	printf("sql init!!\n");
	if(mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0) == NULL){
		printf("mysql_real_connect error!!\n");
		fprintf(stderr, "Mysql connection error : %s", mysql_error(conn));
		return 0;
	}
	printf("mysql_real_connect success!!\n");
	return 1;
}

int insert_query(float t, float h, float pm1_0, float pm2_5, float pm10)
{
	char query[255];
	char _time[32];

	time_t cur_time;
	struct tm *ptm;
	
	time(&cur_time);
	ptm=localtime(&cur_time);
	
	sprintf(_time, "%d-%02d-%02d %02d:%02d:%02d", ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday,
		ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	sprintf(query, "INSERT INTO weather VALUES('%s', '%lf', '%lf', '%lf', '%lf', '%lf')", _time, t, h, pm1_0, pm2_5, pm10);

	if( mysql_query(conn, query))
	{
		printf("inseret_query error!!\n");
		finish_with_error(conn);
		return 0;
	}
	return 1;
}

int disconnect_sql(){
	if(result != NULL)
		mysql_free_result(result);
	if(conn != NULL)
		mysql_close(conn);


	return 1;
}

void finish_with_error(){
	fprintf(stderr, "%s\n", mysql_error(conn));
	mysql_close(conn);
	exit(1);
}
