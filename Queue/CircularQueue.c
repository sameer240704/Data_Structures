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
    //clrscr();
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

void Enqueue(int info) {
    if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = info;
    }
    else if((rear+1)%MAX == front)
        printf("\nQueue is Full!");
    else {
        rear = (rear+1)%MAX;
        queue[rear] = info;
    }
}

void Dequeue() {
    if(front == -1 && rear == -1) 
        printf("\nQueue is Empty!");
    else if(front == rear) {
        printf("\nElement Dequeued : %d", queue[front]);
        front = rear = -1;
    }
    else {
        printf("\nElement Dequeued : %d", queue[front]);
        front = (front+1)%MAX;
    }
}

void Display() {
    int i;
    printf("\n");
    if(front == -1 && rear == -1) 
        printf("\nQueue is Empty!");
    else {
        if(front > rear) {
            for(i=front ; i<MAX ; i++)
                printf("%d <-- ", queue[i]);
            for(i=0 ; i<=rear ; i++)
                printf("%d <-- ", queue[i]);
        }
        else {
            for(i=front ; i<=rear ; i++)
                printf("%d <-- ", queue[i]);
        }
    }
}