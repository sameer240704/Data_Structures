#include<stdio.h>

int partition(int array[], int lb, int ub) {
    int pivot, start, end, temp;
    pivot = array[lb];
    start = lb;
    end = ub;
    while(start < end) {
        while(array[start] <= pivot) 
            start++;
        while(array[end] > pivot)
            end--;
        if(start < end) {
            temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    temp = array[lb];
    array[lb] = array[end];
    array[end] = temp;
    return end;
}

void quickSort(int array[], int lb, int ub) {
    if(lb < ub) {
        int loc = partition(array, lb, ub);
        quickSort(array, lb, loc-1);
        quickSort(array, loc+1, ub);
    }
}

int main() {
    int length, i, lb = 0, ub;
    int array[100];
    //clrscr();
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    printf("\nEnter the array : ");
    for(i = 0 ; i < length ; i++) {
        scanf("%d", &array[i]);
    }
    printf("\n\nUNSORTED ARRAY : ");
    for(i = 0 ; i < length ; i++) {
        printf("%d ", array[i]);
    }
    ub = length - 1;
    quickSort(array, lb, ub);
    printf("\nSORTED ARRAY : ");
    for(i = 0 ; i < length ; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}