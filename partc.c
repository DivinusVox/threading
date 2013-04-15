#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


// Part C:
// Make 4 threads, after running all, print value of count and exit.
//      Wait for the threads to finish.
//	Changes base function -- remove sleep(1).

void* incrementCounter(void* m);

int count;

void main()
{
        count = 0;

	pthread_t t1,t2,t3,t4;

        //start thread 1 w/ incrementCounterC
	pthread_create(&t1, NULL, incrementCounter, NULL);
        //start thread 2 w/ incrementCounterC
	pthread_create(&t2, NULL, incrementCounter, NULL);
        //start thread 3 w/ incrementCounterC
	pthread_create(&t3, NULL, incrementCounter, NULL);
        //start thread 4 w/ incrementCounterC
	pthread_create(&t4, NULL, incrementCounter, NULL);

	//wait for threads to finish
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);


        //print count
	printf("count = %d\n", count);
        //exit
}

void* incrementCounter( void* m )
{
    int i;
    for (i = 0; i < 10; ++i)
    {
        int tempValue = count;
        //sleep(1);
        tempValue = tempValue + 1;
        count = tempValue;
    }
    return NULL;
}
