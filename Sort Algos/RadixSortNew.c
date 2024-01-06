#include<stdio.h>
#include<stdlib.h>

int length; //Declaring this variable globally so no need to pass it again and again in  every function

int *radixSort(int *radix, int *index, int digit, int ptr) {
    int rem, number, temp, j;
    int *sortDigit = (int *)malloc(length * sizeof(int));
    int *sortDigitIndex = (int *)malloc(length * sizeof(int));
    int *radixNew = (int *)malloc(length * sizeof(int));

    if(digit > 0) { //For the maximum number of digits
        for(int i=0 ; i<length ; i++) { 
            j = 0;
            number = radix[i];
            while(j != ptr) { //Every time the digits place(units, hundreds, ...) will be incremented
                rem = number % 10;
                sortDigit[i] = rem; //Store the digits
                number /= 10;
                j++;
            }
            sortDigitIndex[i] = i; //Store the digits index
        }

        //Bubble Sort 
        //To avoid bad time complexity use Quicksort or Mergesort
        for(int i=0 ; i<(length-1) ; i++) {
            for(int j=0 ; j<(length-1) ; j++) {
                if(sortDigit[j] > sortDigit[j+1]) {
                    temp = sortDigit[j]; //Sorting the digits according to the index
                    sortDigit[j] = sortDigit[j+1];
                    sortDigit[j+1] = temp;

                    temp = sortDigitIndex[j]; //Sorting the digit index according to the sorted digits
                    sortDigitIndex[j] = sortDigitIndex[j+1];
                    sortDigitIndex[j+1] = temp;
                }
            }
        }

        /* Main function is being performed over here as the tracing is happening back to the original array 
        and as the original elements are being arranged according to the new sorted digits */
        for(int i = 0; i < length; i++) 
            radixNew[i] = radix[sortDigitIndex[i]]; 

        return radixSort(radixNew, index, --digit, ++ptr); //Repeat the function till digit != 0
    }
    return radix; //Returning the array to findMax
    free(radix);
}

int *findMax(int *radix, int *index) {
    int largest = radix[0], digit = 0;   
     
    for(int i=1 ; i<(length-1) ; i++)
        if(radix[i] > largest)
            largest = radix[i];

    while(largest > 0) {
        digit++;
        largest /= 10;
    }

    int *myArray = radixSort(radix, index, digit, 1);

    return myArray; //Returning array to the main function
    free(myArray);
}

int main() {
    printf("Enter the length of the array : ");
    scanf("%d", &length);

    //Dynamically allocating the memory
    int *radix = (int *)malloc(length * sizeof(int));
    int *index = (int *)malloc(length * sizeof(int));

    printf("\nEnter the array : ");
    for(int i=0 ; i<length ; i++) {
        scanf("%d", &radix[i]);
        index[i] = i;
    }

    int* myArray = findMax(radix, index);

    //Printing the Sorted Array
    printf("\nSORTED ARRAY : ");
    for(int i=0 ; i<length ; i++)
        printf("%d  ", myArray[i]);

    free(myArray);
    return 0;
}