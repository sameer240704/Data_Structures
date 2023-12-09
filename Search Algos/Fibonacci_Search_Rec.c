#include<stdio.h>
#include<conio.h>

int fibonacci_Search(int [], int, int, int, int, int, int);
int fibonacci_Arrange(int [], int, int);
int minimum(int, int);

int main() {
    int i, length, key, offset = -1;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the SORTED ARRAY : ");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d", &key);
    int pos = fibonacci_Arrange(arr, length, key);
    printf("\n%d", pos);
    if(pos >= 0) 
        printf("\nElement %d found at position : %d", key, (pos+1));
    else    
        printf("\nElement not found");
    return 0;
}

int minimum(int a, int b) {
    return (a > b) ? b : a;
}

int fibonacci_Search(int arr[], int length, int key, int Fm, int Fm1, int Fm2, int offset) {
    int i = minimum(offset + Fm2, length - 1);
    if(Fm < 1) 
        return -1;
    else {
        if(arr[i] < key) {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
            return fibonacci_Search(arr, length, key, Fm, Fm1, Fm2, offset);
        }
        else if(arr[i] > key) {
            Fm = Fm2;
            Fm1 -= Fm2;
            Fm2 = Fm - Fm1;
            return fibonacci_Search(arr, length, key, Fm, Fm1, Fm2, offset);
        }
        else 
            return i;
    }
}

int fibonacci_Arrange(int arr[], int length, int key) {
    int Fm, Fm1 = 1, Fm2 = 0, offset = -1;
    Fm = Fm1 + Fm2;
    while(Fm < length) {
        Fm2 = Fm1;
        Fm1 = Fm;
        Fm = Fm1 + Fm2;
    }
    int pos = fibonacci_Search(arr, length, key, Fm, Fm1, Fm2, offset);
    return pos;
}