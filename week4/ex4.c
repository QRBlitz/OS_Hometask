#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
	char a[100];
	char** args = malloc(200 * sizeof(char));
	args[0] = " ";
	while(strcmp(args[0], "exit\n")){
		fgets(a, 100, stdin);
		args = malloc(200 * sizeof(char));
		char* b = strtok(a, " ");
		int x = 0;
		while(b != NULL){
			args[x++] = b;
			b = strtok(NULL, " \n");
		}
		pid_t y = fork();
		if (y == 0){
			execvp(args[0], args);
		}
	}
}
