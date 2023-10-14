#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *newnode, *front = NULL, *rear = NULL, *temp = NULL;

struct Node* createNode(int info) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = info;
    newnode -> next = NULL;
    return newnode;
}

void Enqueue(int info) {
    newnode = createNode(info);
    if(front == NULL && rear == NULL)
        front = rear = newnode;
    else {
        rear -> next = newnode;
        rear = newnode;
    }
}

void Dequeue() {
    if(front == NULL) 
        printf("\nQueue is Empty!");
    else {
        temp = front;
        front = front -> next;
        printf("\nElement popped : %d", temp -> data);
        free(temp);
    }
}

void QueueFront() {
    if(front == NULL) 
        printf("\nQueue is Empty!");
    else 
        printf("\nFront of the Queue is : %d", front -> data);
}

void QueueRear() {
    if(front == NULL) 
        printf("\nQueue is Empty!");
    else 
        printf("\nRear of the Queue is : %d", rear -> data);
}

void Display() {
    if(front == NULL) 
        printf("\nQueue is Empty!");
    else {
        temp = front;
        printf("\n");
        while(temp != NULL) {
            printf("%d <-- ", temp -> data);
            temp = temp -> next;
        }
    }
}

int main()
{
    int choice, data;
    do{
        printf("\nEnter choice\n1. Enqueue\n2. Dequeue\n3. Front of Queue\n4. Rear of Queue\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter data : ");
                    scanf("%d", &data);
                    Enqueue(data);
                    Display();
                    break;
            case 2: Dequeue();
                    Display();
                    break;
            case 3: QueueFront();
                    break;
            case 4: QueueRear();
                    break;
            case 5: Display();
                    break;
            case 6: exit(0);
                    break;
            default:printf("\nEnter a valid choice!");
        }
    }
    while(choice != 6);
    return 0;
}