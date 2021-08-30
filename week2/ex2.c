#include <stdio.h>
#include <string.h>

int main(){
	char str[20];
	printf("Enter the word\n");
	scanf("%s", str);
	for(int i = strlen(str); i > -1; i--){
		printf("%c", str[i]);
	}
	printf("\n");
}
