#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	// TO DO : check isrun?


	if(!strcmp(argv[1], "run"))
		printf("my instruction is run!\n");
	else if(!strcmp(argv[1], "stop"))
		printf("my instruction is stop!\n");



	return 0;
}
