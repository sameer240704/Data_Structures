#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int length, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if(left < length && arr[left] > arr[largest])
		largest = left;

	if(right < length && arr[right] > arr[largest])
		largest = right;

	if(largest != index) {
		swap(&arr[index], &arr[largest]);	
		heapify(arr, length, largest);
	}
}

void heapSort(int arr[], int length) {
	for(int i=(length/2-1) ; i>=0 ; i--)
		heapify(arr, length, i);

	for(int i=(length-1) ; i>=0 ; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	int arr[MAX], length;
    printf("Enter the length of the array : ");
    scanf("%d", &length);
	printf("Enter the array : ");
    for(int i=0 ; i<length ; i++) 
        scanf("%d", &arr[i]);
	heapSort(arr, length);
	printf("Sorted array is : ");
	for(int i=0 ; i<length ; i++)
		printf("%d ", arr[i]);
}