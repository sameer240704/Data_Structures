#include<stdio.h>
#include<conio.h>
int binary_search(int [], int , int , int , int );

int main() {
    int i, length, first, last, mid, key;
    printf("Enter the length of the array : ");
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
    mid = (first + last)/2;
    int pos = binary_search(arr, first, last, mid, key);
    if(pos >= 0)
        printf("\nElement %d found at position : %d", key, (pos+1));
    else    
        printf("\nElement not found");
}

int binary_search(int arr[], int first, int last, int mid, int key) {
    if(first <= last) {
        mid = (first+last)/2;
        if(arr[mid] < key)
            return binary_search(arr, (mid+1), last, mid, key);
        else if(arr[mid] > key)
            return binary_search(arr, first, (mid-1), mid, key);
        else 
            return mid;
    }
    return -1;
}