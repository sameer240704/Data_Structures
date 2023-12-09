#include<stdio.h>
#include<conio.h>

int main() {
    int i, j, length, smallest, temp;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the array : ");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n***UNSORTED ARRAY***\n");
    for(i=0 ; i<length ; i++) {
        printf("%d ", arr[i]);
    }
    for(i = 0; i<length-1; i++) {
		smallest = i;
		for(j=(i+1) ; j<length ; j++) {
			if(arr[smallest] > arr[j])
			    smallest = j;
		}
		if(smallest != i) {
			temp = arr[i];
			arr[i] = arr[smallest];
			arr[smallest] = temp;
		}
	}
    printf("\n***SORTED ARRAY***\n");
    for(i=0 ; i<length ; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}