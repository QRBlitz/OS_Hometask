#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

	for (int i = 0; i < 3; i++) {
		pid_t c = fork();
	}
	sleep(15);
	return EXIT_SUCCESS;
	
}
