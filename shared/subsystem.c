#include <stdio.h>

int init()
{
	printf("Initializing subsystem...\n");
	return 0;
}

/*

gcc -c subsystem.c
gcc -shared -o subsystem.dll subsystem.o

or

gcc subsystem.c -o subsystem.dll -shared
gcc -o main main.c -L./ -lsubsystem -lpthread

*/