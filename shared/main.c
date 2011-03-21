#include <stdio.h>
#include <pthread.h>

/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 100 )
	{
		usleep(1);
		printf("threadFunc says: %s\n",str);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t pth;	// this is our thread identifier
	int i = 0;

	pthread_create(&pth,NULL,threadFunc,"foo");
	
	while(i < 100)
	{
		usleep(1);
		printf("main is running...\n");
		++i;
	}

	printf("main waiting for thread to terminate...\n");
	pthread_join(pth,NULL);

	init();

	return 0;
}

/*

	1. gcc -c subsystem.c
	2. gcc -shared -fPIC -o subsystem.dll subsystem.o
	3. gcc -o main main.c -L./ -lsubsystem -lpthread
	   or
	   gcc -o main main.c -L./ -lsubsystem
	   gcc -o main main.c -lpthread

	1. gcc -c -fPIC subsystem.c 
	2. gcc -shared subsystem.o -o subsystem.so
	3. 
	4. 

*/
