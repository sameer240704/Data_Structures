#include<stdio.h>
#include<conio.h>

int main() {
    int i, j, length, temp;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the array : ");
    for(i=0; i<length; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n****UNSORTED ARRAY***\n");
    for(i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    for(i=0 ; i<(length-1) ; i++) {
        for(j=0 ; j<(length-1) ; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\n\n****SORTED ARRAY***\n");
    for(i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}