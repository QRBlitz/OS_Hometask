#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int product;
int max = 5;
int products[5];

void* produce(void *i)
{
	while(1)
	{
		while(product >= max);
		if(product >= max){
			printf("Fatal Error! Buffer is full\n");
			exit(1);
		}
		printf("Producer produced product\n");
		product++;
		products[product] = 1;
	}
}
void* consume(void *i)
{
	while(1)
	{
		while(product <= 0);
		if(product <= 0){
			printf("Fatal Error! Buffer is empty\n");
			exit(1);
		}
		printf("Consumer consumed product\n");
		product--;
		products[product] = 0;
		
	}
}

int main()
{

	pthread_t producer;
	pthread_t consumer;
	
	pthread_create(&producer, NULL, produce, NULL);
	pthread_create(&consumer, NULL, consume, NULL);
	
	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);
	
	return 0;
}
