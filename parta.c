#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Part A:
// Make 4 threads, after running all, print value of count and exit.
// 	Do not wait for the threads to finish.

void* incrementCounter(void* m);

int count;

void main()
{
	count = 0;

	pthread_t t1, t2, t3, t4;

	//start thread 1
	pthread_create(&t1, NULL, incrementCounter, (void*)&count);
	//start thread 2
	pthread_create(&t2, NULL, incrementCounter, (void*)&count);
	//start thread 3
	pthread_create(&t3, NULL, incrementCounter, (void*)&count);
	//start thread 4
	pthread_create(&t4, NULL, incrementCounter, (void*)&count);

	printf("%d\n", count);
	//print count
	//exit
}

void* incrementCounter( void* m )
{
    int i;
    for (i = 0; i < 10; ++i)
    {
        int tempValue = count;
        sleep(1);
        tempValue = tempValue + 1;
        count = tempValue;
    }
 
    return NULL;
}
