#include<stdio.h>
#include<conio.h>

int minimum(int a, int b) {
    return (a > b) ? b : a;
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
    while(fib[k] > 0) {
        int index = minimum(offset + fib[k-2], length - 1);
        if(key == array[index]) {
            printf("\nElement found at index %d", (index+1));
            break;
        }
        else if(key < array[index]) {
            k = k - 1;
            offset = index;
        }
        else if(key > array[index])
            k = k - 2;
        if(fib[k] == 0) {
            printf("\nElement not found");
            break;
        }
    }
    getch();
    return 0;
}