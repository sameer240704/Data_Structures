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
    for(i=0 ; (i<length-1) ; i++) {
        for(j=i ; j<(length - 1) ; j++) {
            if(arr[i] > arr[j+1])
                smallest = j+1;
        }
        if(smallest != i) {
            temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
    }
    printf("\n***SORTED ARRAY***\n");
    for(i=0 ; i<length ; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}