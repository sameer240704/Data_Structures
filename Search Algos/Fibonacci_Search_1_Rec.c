#include<stdio.h>
#include<conio.h>

int minimum(int a, int b) {
    return (a > b) ? b : a;
}

int fibonacci_Search(int arr[], int fib[], int key, int offset, int k, int length) {
    if(fib[k] > 0) {    
        int index = minimum(offset + fib[k-2], length - 1);
        if(key == arr[index]) 
            return (index+1);
        else if(key < arr[index]) 
            return (arr, fib, key, index, (k-1), length);
        else 
            return (arr, fib, key, offset, (k-2), length);
    }
    return 0;
}

int main() {
    int length, i, key, offset = -1;
    printf("\nEnter the length of array : ");
    scanf("%d", &length);
    int array[length], fib[length + 1];
    printf("\nEnter the SORTED array : ");
    for(i = 0 ; i < length ; i++) {
        scanf("%d", &array[i]);
    }
    fib[0] = 0;
    fib[1] = 1;
    for(i = 2 ; i <= length ; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d", &key);
    int k = length - 1;
    int pos = fibonacci_Search(array, fib, key, offset, k, length);
    if(pos > 0) 
        printf("\nElement found at position %d", pos);
    else   
        printf("\nElement not found!");
    getch();
    return 0;
}