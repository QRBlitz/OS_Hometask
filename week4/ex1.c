#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

	int n = 93;
	pid_t x = fork(); // process id of the created process
	if (x == 0) { // Child process
		printf("Hello from Child [%d - %d]\n", getpid(), n);
		// getpid() - prints the pid of the current process
	}
	else{
		if(x > 0) { //Parent Process
			printf("Hello from Parent [%d - %d]\n", getpid(), n);
		}
		else { // Error when trying to create a process using fork()
			return EXIT_FAILURE;
		}
	}
	
	return EXIT_SUCCESS;
	
}
