// Part D:
// Make 4 threads, after running all, print value of count and exit.
//      Wait for the threads to finish. Use mutex.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* incrementCounter( void* m );

int count;
pthread_mutex_t mutexLock;

void main()
{
	pthread_mutex_init(&mutexLock, NULL); 
	count = 0;
	
	pthread_t t1,t2,t3,t4;
	
	pthread_create(&t1, NULL, incrementCounter, NULL); //start thread 1
	pthread_create(&t2, NULL, incrementCounter, NULL); //start thread 2
	pthread_create(&t3, NULL, incrementCounter, NULL); //start thread 3
	pthread_create(&t4, NULL, incrementCounter, NULL); //start thread 4

	//wait for threads to come back
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	//print count
	
	printf("partd: count is %d\n", count);
	return;//exit
}


void* incrementCounter( void* m )
{
	int i;
	pthread_mutex_lock(&mutexLock); //lock here
	
	for (i=0; i<10; i++)
	{
		int tempValue = count;
		sleep(1);
		tempValue = tempValue + 1;
		count = tempValue;
	}
	pthread_mutex_unlock(&mutexLock); //unlock here

	return NULL;
}