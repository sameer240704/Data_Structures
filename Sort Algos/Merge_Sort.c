#include<conio.h>
#include<stdio.h>

int partition(int array[], int lb, int mid, int ub) {
    int i = lb, j = mid+1, k = lb, array1[100];
    while(i <= mid && j <= ub) {
        if(array[i] <= array[j])
            array1[k++] = array[i++];
        else
            array1[k++] = array[j++];
    }
    if(i > mid) 
        while(j <= ub) 
            array1[k++] = array[j++];
    else 
        while(i <= mid)
            array1[k++] = array[i++];

    for(i=lb ; i<=ub ; i++) 
        array[i] = array1[i];
}

int mergeSort(int array[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub)/2;
        mergeSort(array, lb, mid);
        mergeSort(array, (mid+1), ub);
        partition(array, lb, mid, ub);
    }
}

int main() {
    int length, lb = 0, ub, array[100], i;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    printf("\nEnter the array : ");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &array[i]);
    }
    ub = length - 1;
    mergeSort(array, lb, ub);
    printf("\nSORTED ARRAY -> ");
    for(i=0 ; i<length ; i++) {
        printf("%d ", array[i]);
    }
}