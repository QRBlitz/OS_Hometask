#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* myThread (void* i) {
	printf("          Hello from thread #%i!\n", * (int*)i);
	pthread_exit(NULL);
}

int main() {

	int n;
	printf("Enter a number\n");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		pthread_t thread;
		printf("Creating Thread #%i\n", i);
		pthread_create(&thread, NULL, myThread, &i);
		printf("   >> Thread #%d created!\n", i);
		pthread_join(thread, NULL);
	}

	
	return 0;
}
