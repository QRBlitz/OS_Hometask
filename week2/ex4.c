#include <stdio.h>

void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main() {
	int num1, num2;
	printf("Enter first number\n");
	scanf("%i", &num1);
	printf("Enter second number\n");
	scanf("%i", &num2);
	swap(&num1, &num2);
	printf("Number 1 = %i\nNumber 2 = %i\n", num1, num2);
}
