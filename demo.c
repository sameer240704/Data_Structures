#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *temp = NULL, *node, *tos = NULL;

struct Node *createNode(int info) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = info;
    node -> next = NULL;
    return node;
}

void push(int info) {
    node = createNode(info);
    node -> next = tos;
    tos = node;
}

void pop() {
    if(tos == NULL)
        printf("\nStack is Empty");
    else {
        temp = tos;
        tos = tos -> next;
        printf("\nElement Popped : %d", temp -> data);
        free(temp);
    }
}

void stackTop() {
    if(tos == NULL)
        printf("\nStack is Empty");
    else {
        printf("\nStack Top : %d", tos -> data);
    }
}

void Display() {
    if(tos == NULL)
        printf("\nStack is Empty");
    else {
        temp = tos;
        while(temp != NULL) {
            printf("\n\t\t\t%d", temp -> data);
            printf("\n\t\t_____________");
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
                    Display();
                    break;
            case 2: pop();
                    break;
            case 3: stackTop();
                    break;
            case 4: Display();
                    break;
            case 5: exit(0);
                    break;
            default:printf("\nEnter a valid choice!");
        }
    }
    while(choice != 5);
    return 0;
}