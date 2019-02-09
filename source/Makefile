CC = gcc

airChecker : dht.o main.o pms.o sql.o
	gcc -o airChecker dht.o main.o pms.o sql.o -lwiringPi -lmariadbclient
	rm *.o

dht.o : dht.c
	gcc -c -o dht.o dht.c -lwiringPi

main.o : main.c
	gcc -c -o main.o main.c -lwiringPi -lmariadbclient

pms.o : pms.c
	gcc -c -o pms.o pms.c -lwiringPi

sql.o : sql.c
	gcc -c -o sql.o sql.c -lmariadbclient

clean :
	rm -rf *.o airChecker
