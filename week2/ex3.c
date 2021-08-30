#include <stdio.h>

int main(int argc, char *argv[]){
	int a;
	if (argc > 1){
		sscanf(argv[1], "%i", &a);
	}
	else {
		printf("Please enter integer\n");
		return 0;
	}
	int b = a * 2 - 1, count = 1;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b - count; j++){
			printf(" ");
		}
		for(int x = 0; x < count; x++){
			printf("* ");
		}
		count += 2;
		printf("\n");
	}
}
