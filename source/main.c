#include <signal.h>
#include "dht.h"
#include "sql.h"

int dht11_val[5];
float t, h;

void INThandler(int sig)
{
	disconnect_sql();
	printf("get signal success disconnect_sql()");
	exit(0);
}

int main(void){

	signal(SIGINT, INThandler);
	if(!connect_sql()){
		printf("fail connect sql\n");
	}

	while(1){
		if(!read_dht_val()){
			printf("dht11, fail read!!\n");
			delay(3000);
			continue;
		}
		printf("dht11, read success t: %lf, h: %lf\n", t, h);
	
		insert_query(t, h);
		delay(3000);
	}
	disconnect_sql();
	printf("success disconnect_sql()");
	
		return 0;
}
