#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
void Enqueue(int );
void Dequeue();
void Display();
int front = -1, rear = -1, queue[MAX];

int main() {
    int choice, data;
    clrscr();
    do {
        printf("\nEnter choice\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("\nEnter data : ");
                    scanf("%d", &data);
                    Enqueue(data);
                    Display();
                    break;
            case 2: Dequeue();
                    Display();
                    break;
            case 3: Display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nEnter a valid choice");
        }
    }
    while(choice != 4);
    getch();
    return 0;
}