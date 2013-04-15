#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void* incrementCounter( void* m )
{
	int i;
	for (i=0; i<10; i++)
	{
		int tempValue = count;
		sleep(1);
		tempValue = tempValue + 1;
		count = tempValue;
	}

	return NULL;
}

void* incrementCounterC( void* m )
{
	int i;
	for (i=0; i<10; i++)
	{
		int tempValue = count;
		tempValue = tempValue + 1;
		count = tempValue;
	}

	return NULL;
}
