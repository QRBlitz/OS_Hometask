#include <stdio.h>

void sort(int arr[], int num) {
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num - 1; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for(int i = 0 ; i < num; i++){
		printf("%d ", arr[i]);
	}
}

int main() {
	int arr[20], num;
	scanf("%d", &num);
	for(int i = 0; i < num; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, num);
}
  
