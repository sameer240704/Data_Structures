#include<conio.h>
#include<stdio.h>

void insertionSort(int [], int);

int main()
{
	int length, i;
	printf("\nEnter the length of the array : ");
	scanf("%d", &length);
	int array[length];
	printf("\nEnter the UNSORTED array : ");
	for(i=0 ; i<length ; i++) {
		scanf("%d", &array[i]);
	}
	printf("\n***UNSORTED ARRAY*** -> ");
	for(i=0 ; i<length ; i++) {
		printf("%d ", array[i]);
	}
	insertionSort(array, length);
	printf("\n***SORTED ARRAY*** -> ");
	for(i=0 ; i<length ; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

void insertionSort(int array[], int length)
{
	int i, j, key;
	for(i = 1; i < length; i++) {
		key = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}
