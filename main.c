#include "dht.h"
#include "sql.h"

int dht11_val[5];
float t, h;

int main(void){

	if(!read_dht_val()){
		printf("dht11, fail read!!\n");
		return -1;
	}
	printf("dht11, read success t: %lf, h: %lf\n", t, h);


	printf("Test Program Start\n");
	if(!connect_sql()){
		printf("fail connect sql\n");
		return -1;
	}

	insert_query(t, h);
	disconnect_sql();
	printf("success disconnect_sql()");


	return 0;
}
