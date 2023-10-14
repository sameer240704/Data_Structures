#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *newnode, *tos = NULL, *temp = NULL;

struct Node* createNode(int info) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = info;
    newnode -> next = NULL;
    return newnode;
}

void push(int info) {
    newnode = createNode(info);
    newnode -> next = tos;
    tos = newnode;
}

void pop() {
    if(tos == NULL) 
        printf("\nStack is Empty!");
    else {
        temp = tos;
        tos = tos -> next;
        printf("\nElement popped : %d", temp -> data);
        free(temp);
    }
}

void stackTop() {
    if(tos == NULL)
        printf("\nStack is Empty!");
    else 
        printf("\nTop of the Stack is : %d", tos -> data);
}

void display() {
    if(tos == NULL)
        printf("\nStack is Empty!");
    else {
        temp = tos;
        while(temp != NULL) {
            printf("\n\t\t\t\t%d", temp -> data);
            printf("\n\t\t\t\t_____________");
            temp = temp -> next;
        }
    }
}

int main()
{
    int choice, data;
    do{
        printf("\nEnter choice\n1. Push\n2. Pop\n3. Top of Stack\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter data : ");
                    scanf("%d", &data);
                    push(data);
                    display();
                    break;
            case 2: pop();
                    break;
            case 3: stackTop();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
                    break;
            default:printf("\nEnter a valid choice!");
        }
    }
    while(choice != 5);
    return 0;
}