#include <stdio.h>
#include <stdlib.h>

int main() {

	char **s = malloc(sizeof(char*)); // First fault memory wasn't allocated
	char foo[] = "Hello World";
	
	*s = foo;
	printf("s is %p\n", s); // Second fault trying to print **char while it is **char
	
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	
	return 0;

}
