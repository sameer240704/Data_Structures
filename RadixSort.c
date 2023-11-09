#include<stdio.h>
#include<conio.h>
#include<string.h>

int array[100], units[100], tens[100], hundreds[100], thousands[100];
void digitSeparator(int );
void digitSorter(int );
void digitCreator();

int main() {
    int i, length;
    printf("Enter the length of the array : ");
    scanf("%d", &length);
    printf("\nEnter the array to be sorted : ");
    for(i=0 ; i<length ; i++) {
        scanf("%d", &array[i]);
    }
    digitSeparator(length);
    digitSorter(length);
    /*printf("\n\n");
    for(i=0 ; i<length ; i++) {
        printf("%d ", units[i]);
    }
    printf("\n\n");
    for(i=0 ; i<length ; i++) {
        printf("%d ", tens[i]);
    }
    printf("\n\n");
    for(i=0 ; i<length ; i++) {
        printf("%d ", hundreds[i]);
    }
    printf("\n\n");
    for(i=0 ; i<length ; i++) {
        printf("%d ", thousands[i]);
    }*/
    return 0;
}

void digitSeparator(int length) {
    int i, counter = 0, rem;
    for(i=0 ; i<length ; i++) {
        int num = array[i];
        int j = 0;
        while(num > 0) {
            rem = num % 10;
            if(j == 0) 
                units[i] = rem;
            else if(j == 1)
                tens[i] = rem;
            else if(j == 2)
                hundreds[i] = rem;
            else if(j == 3)
                thousands[i] = rem;
            j++;
            num = num / 10;
        }
        if(tens[i] == -1)
            tens[i] = 0;
        if(hundreds[i] == -1)
            hundreds[i] = 0;
        if(thousands[i] == -1)
            thousands[i] = 0;
    }
}

void digitSorter(int length) {
    
}