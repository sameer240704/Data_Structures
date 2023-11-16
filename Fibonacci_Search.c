#include <stdio.h>
int min(int, int);
int fibonacci_search(int[], int, int);
int min(int a, int b){
    return (a > b) ? b : a;
}

int fibonacci_search(int arr[], int n, int key){
    int offset = -1;
    int Fm2 = 0;
    int Fm1 = 1;
    int Fm = Fm2 + Fm1;
    while (Fm < n) {
        Fm2 = Fm1;
        Fm1 = Fm;
        Fm = Fm2 + Fm1;
    }
    while (Fm > 1) {
        int i = min(offset + Fm2, n - 1);
        if (arr[i] < key) {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
        } else if (arr[i] > key) {
            Fm = Fm2;
            Fm1 = Fm1 - Fm2;
            Fm2 = Fm - Fm1;
        } else {
            return i;
        }
        printf("\n");
        for(int j=0 ; j<n ; j++) {
            if(j==i)
                printf("|%d| ", arr[j]);
            else    
                printf("%d ", arr[j]);
        }
        printf("\n");
    }
    if (Fm1 && arr[offset + 1] == key)
        return offset + 1;
    return -1;
}
int main(){
    int i, key, pos, length;
    printf("Enter the length of your array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the SORTED ARRAY : \n");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d", &key);
   pos = fibonacci_search(arr, length, key);
    if(pos >= 0)
        printf("The element is found at index %d", pos);
    else
        printf("Unsuccessful Search");
}