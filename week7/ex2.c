#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	printf("Enter number of array elements: ");
	scanf("%d", &n);
	int *arr = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		arr[i] = i;
		printf("arr[%i]==%i\n", i, arr[i]);
	}
	free(arr);
}
