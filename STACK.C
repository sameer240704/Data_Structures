#include<conio.h>
#include<stdio.h>
#define MAX 5
void push(int );
void pop();
void stackTop();
void display();
int tos = -1, stack[MAX], i = 0;

int main() {
    int choice, data;
    do {
        printf("\nEnter choice\n1. Push\n2. Pop\n3. Top of Stack\n4. Display\n5. Exit\t");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("\nEnter your data : ");
                    scanf("%d", &data);
                    push(data);
                    display();
                    break;
            case 2: pop();
                    display();
                    break;
            case 3: stackTop();
                    break;
            case 4: display();
                    break;
            case 5: //exit(0);
                    break;
            default: printf("\nEnter a valid choice!");
        }
    }
    while(choice != 5);
    return 0;
}

void push(int info) {
    if(tos == (MAX-1))
        printf("\nStack is Full!");
    else {
        tos++;
        stack[tos] = info;
    }
}

void pop() {
    if(tos == -1)
        printf("\nStack is Empty!");
    else {
        printf("\nElement Deleted : %d", stack[tos]);
        tos--;
    }
}

void stackTop() {
    if(tos == -1)
        printf("\nStack is Empty!");
    else 
        printf("\nTop of Stack is %d", stack[tos]);
}

void display() {
    if(tos == -1)
        printf("\nStack is Empty!");
    else {
        for(i=tos ; i>=0 ; i--) {
            printf("\n\t\t\t\t%d", stack[i]);
            printf("\n\t\t\t\t____________");
        }
    }
}