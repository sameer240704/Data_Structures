#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void Enqueue(int);
void Dequeue();
void QueueFront();
void QueueRear();
void Display();

int front = -1, rear = -1, queue[MAX];

int main() {
    int choice, data;
    do {
        printf("\nEnter choice\n1. Enqueue\n2. Dequeue\n3. Front of Queue\n4. Rear of Queue\n5. Display\n6. Exit\t");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                Enqueue(data);
                Display();
                break;
            case 2:
                Dequeue();
                Display();
                break;
            case 3:
                QueueFront();
                break;
            case 4:
                QueueRear();
                break;
            case 5:
                Display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice!");
        }
    } while (choice != 6);
    return 0;
}

void Enqueue(int info) {
    if(rear == (MAX - 1))
        printf("\nQueue is Full!");
    else if(front == -1) {
        front = rear = 0;
        queue[rear] = info;
    } 
    else 
        queue[++rear] = info;
}

void Dequeue() {
    if (front == -1)
        printf("\nQueue is Empty!");
    else {
        printf("\nElement Dequeued: %d", queue[front]);
        if (front == rear) 
            front = rear = -1;
        else 
            front++;
    }
}

void QueueFront() {
    if (front == -1) 
        printf("\nQueue is Empty!");
    else 
        printf("\nFront of queue: %d", queue[front]);
}

void QueueRear() {
    if (rear == -1) 
        printf("\nQueue is Empty!");
    else 
        printf("\nRear of queue: %d", queue[rear]);
}

void Display() {
    int i;
    if(front == -1)
        printf("\nQueue is Empty!");
    else {
        printf("\nFRONT: ");
        for(i = front ; i <= rear ; i++) {
            printf("%d", queue[i]);
            if(i < rear)
                printf(" <-- ");
        }
        printf(" :REAR\n");
    }
}