#include<stdio.h>
#include<conio.h>

int main() {
    int i, length, first=0, mid, last, key;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the sorted array : ");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d", &key);
    first = 0;
    last = length - 1;
    while(first <= last) {
        mid = (first+last)/2;
        if(arr[mid] < key) 
            first = mid+1;
        else if(arr[mid] > key)
            last = mid-1;
        else    
            first = last + 1;
    }
    if(key == arr[mid])
        printf("\nElement found at position : %d", (mid+1));
    else 
        printf("\nElement not found");
    return 0;
}