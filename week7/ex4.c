#include<stdio.h>
#include<stdlib.h>

void* ownRealloc(int* ptr, size_t oldSize, size_t newSize){
	//Free memory if new size equal to zero
	if(newSize == 0) {
		free(ptr);
		return NULL;
	}
	//Return malloc(size) if ptr is null
	if(ptr == NULL){
		return malloc(newSize * sizeof(int));
	}
	
	//Allocate new memory and copy data
	int* newPtr = malloc(newSize * sizeof(int));
	for(int i = 0; i < newSize; i++){
		newPtr[i] = ptr[i];
	}
	
	//Free initial pointer
	free(ptr);
	
	return newPtr;
}

int main() {

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size: ");
	int n1 = 0;
	scanf("%d", &n1);
	
	//Create a new array of n1 ints
	int* a1 = malloc(n1 * sizeof(int));
	for(int i = 0; i < n1; i++) {
		//Set each value in a1 to 100
		a1[i] = 100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	
	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);
	
	//Dynamically change the array to size n2 using my own realloc
	a1 = ownRealloc(a1, n1, n2);
	
	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
	if(n2 > n1) {
		for(int i = n1; i < n2; i++) {
			a1[i] = 0;
		}
	}
	
	for(int i = 0; i < n2; i++) {
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	//Free the array
	free(a1);
	
	return 0;
}
