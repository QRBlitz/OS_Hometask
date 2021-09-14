#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char input[200];
	while(strcmp(input, "exit")){
		scanf("%s", input);
		system(input);
	}

}
