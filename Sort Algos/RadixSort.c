#include<stdio.h>  
#include<conio.h>

int findMax(int [], int);
void countingSort(int [], int, int);
void radixSort(int [], int); 
  
int main() {  
    int length, i;
    printf("\nEnter the length of the array : ");
    scanf("%d", &length);
    int arr[length];
    printf("\nEnter the UNSORTED array : ");
    for (i = 0; i < length; ++i) {  
        scanf("%d", &arr[i]);  
    } 
    printf("\n***UNSORTED ARRAY*** -> ");
    for(i = 0; i < length; ++i) {  
        printf("%d  ", arr[i]);  
    } 
    radixSort(arr, length);  
    printf("\n***SORTED ARRAY*** -> ");
    for(i = 0; i < length; i++) {  
        printf("%d  ", arr[i]);  
    }  
    getch();
}

//This is a Simple Linear Search function which gives us the maximum number in the entire array and returns it
int findMax(int arr[], int length) {  
    int i;
    int maxElement = arr[0];  
    for(i = 1; i < length; i++) {  
        if(arr[i] > maxElement)  
        maxElement = arr[i];  
    }  
    return maxElement; 
}  
  
void countingSort(int arr[], int length, int pos) 
{  
    int i;
    int result[length + 1];  
    int count[100] = {0};    
    
    for (i = 0; i < length; i++) {
        count[(arr[i] / pos) % 10]++;  
    }
        
    for (i = 1; i < 100; i++) {
        count[i] += count[i - 1]; 
    } 
    
    for (i = length-1; i >= 0; i--) {  
        result[count[(arr[i] / pos) % 10] - 1] = arr[i];  
        count[(arr[i] / pos) % 10]--;  
    }  

    for (i = 0; i < length; i++)  
        arr[i] = result[i];  
}  
  
void radixSort(int arr[], int length) {  
    int pos;
    int maxElement = findMax(arr, length);  
    for (pos = 1; maxElement / pos > 0; pos *= 10) {
        countingSort(arr, length, pos);  
    }
} 