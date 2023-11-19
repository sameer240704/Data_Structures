#include<stdio.h>
#include<conio.h>

int main() {
    int i, length, key, pos;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the array : ");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d", &key);
    i=0;
    while(i < length) {
        if(arr[i] == key) 
            pos = i;
        i++;
    }
    if(pos >= 0)
        printf("\nElement %d found at position : %d", key, (pos+1));
    else    
        printf("\nElement not found");
}