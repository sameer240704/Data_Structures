#include<stdio.h>
#include<conio.h>
int minimum(int, int );
int fibonacci_search(int [], int, int);

int main() {
    int i, length, key;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the SORTED ARRAY : ");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d", &key);
    int pos = fibonacci_search(arr, length, key);
    if(pos >= 0)
        printf("\nElement %d found at position : %d", key, (pos+1));
    else 
        printf("\nElement not found");
    return 0;
}

int minimum(int a, int b) {
    return (a > b) ? b : a;
}

int fibonacci_search(int arr[], int length, int key) {
    int offset = -1, Fm, Fm1 = 1, Fm2 = 0, i;
    Fm = Fm1 + Fm2;
    while(Fm < length) {
        Fm2 = Fm1;
        Fm1 = Fm;
        Fm = Fm1 + Fm2;
    }
    while(Fm > 1) {
        i = minimum(offset + Fm2, length - 1);
        if(arr[i] < key) {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
        }
        else if(arr[i] > key) {
            Fm = Fm2;
            Fm1 -= Fm2;
            Fm2 = Fm - Fm1;
        }
        else 
            return i;
    }
    if(Fm1 && arr[offset+1] == key)
        return (offset + 1);
    return -1;
}