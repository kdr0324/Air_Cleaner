#include <signal.h>
#include "dht.h"
#include "sql.h"
#include "pms.h"

const int CHECK_TIME=3000;

//ctrl+c signal handler for disconnect mysql, and sensor connect
void INThandler(int sig)
{
	disconnect_sql();
	close_pms();
	printf("get signal success disconnect_sql()");
	printf("get signal success close_pms()");
	exit(0);
}

int main(void){

	//signal handler for SIGINT(ctrl+c)
	signal(SIGINT, INThandler);
	//connect mysql db
	if(!connect_sql()){
		printf("fail connect sql\n");
		return 0;
	}
	//connect Uart Serial PMS Sensor
	if(!open_pms()) {
		printf("fail open PMS\n");
		return 0;
	}

	//read data sensor and send data to db
	while(1){
		delay(CHECK_TIME);

		//read dht11
		if(!read_dht_val()){
			printf("dht11, fail read!!\n");
			continue;
		}
		printf("dht11, read success t: %lf, h: %lf\n", t, h);

		//read PMS7003
		if(!read_pms()){
				printf("fail read pms data!!\n");
				continue;
		}
	
		//insert query
		insert_query(t, h, PM1_0, PM2_5, PM10);
	}

	//disconnect code but not work
	disconnect_sql();
	printf("success disconnect_sql()");
	
	return 0;
}
