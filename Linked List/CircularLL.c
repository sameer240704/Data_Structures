#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *node = NULL, *list = NULL, *last = NULL, *temp = NULL, *p = NULL;

int count = 0;

struct Node *createNode(int info) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = info;
    node -> next = NULL;
    count++;
    return node;
}


void AddAtFront(int info) {
    node = createNode(info);
    if(list == NULL)
        list = last = node;
    else {
        node -> next = list;
        list = node;
    }
    last -> next = list;
}

void AddAtEnd(int info) {
    node = createNode(info);
    if(list == NULL)
        list = last = node;
    else {
        last -> next = node;
        last = node;
    }
    last -> next = list;
}

void AddAtPosition(int info, int pos) {
    if(pos == 1)
        AddAtFront(info);
    else if(pos == (count+1))
        AddAtEnd(info);
    else {
        node = createNode(info);
        temp = list;
        for(int i=1 ; i<pos ; i++) {
            p = temp;
            temp = temp -> next;
        }
        p -> next = node;
        node -> next = temp;
    }
}

void DeleteAtFront() {
    if(list == NULL)
        printf("\nList is Empty!\n");
    else {
        temp = list;
        list = list -> next;
        printf("\nNode deleted : %d\n", temp -> data);
        free(temp);
        count--;
    }
    last -> next = list;
}

void DeleteAtEnd() {
    if(list == NULL)
        printf("\nList is Empty!\n");
    else {
        temp = list;
        while(temp -> next != last) {
            temp = temp -> next;
        }
        printf("\nNode deleted : %d\n", last -> data);
        temp -> next = list;
        last = temp;
        count--;
    }
}

void DeleteAtPosition(int pos) {
    if(pos == 1)
        DeleteAtFront();
    else if(pos == (count+1))
        DeleteAtBack();
    else {
        temp = list;
        for(int i=1 ; i<pos ; i++) {
            p = temp;
            temp = temp -> next;
        }
        printf("\nNode Deleted : %d\n", temp -> data);
        p -> next = temp -> next;
        free(temp);
    }
}

int Search(int info) {
    int pos = 1;
    if(list == NULL)
        printf("\nList is Empty!");
    else {
        temp = list;
        while(temp != list) {
            if(temp -> data == info) {
                return pos;
            }
            temp = temp -> next;
            pos++;
        }
    }
    return -1;
}

void SearchAndDelete(int info) {
    int pos = Search(info);
    if(pos != 0)
        DeleteAtPosition(pos);
    else    
        printf("\nNo Data Found!");
}

void Display() {
    if(list == NULL)
        printf("\nList is Empty!\n");
    else {
        temp = list;    
        do {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        } while(temp != list);
        printf("%d -> ", temp -> data);
    }
}

int main() {
    int choice, data, pos;
    do {
        printf("\nEnter choice: \n1. AAF\n2. AAE\n3. AAP\n4. DAF\n5. DAE\n6. EXIT\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("\nEnter data : ");
                    scanf("%d", &data);
                    AddAtFront(data);
                    Display();
                    break;
            case 2: printf("\nEnter data : ");
                    scanf("%d", &data);
                    AddAtEnd(data);
                    Display();
                    break;
            case 3: printf("\nEnter data : ");
                    scanf("%d", &data);
                    printf("\nEnter position : ");
                    scanf("%d", &pos);
                    AddAtPosition(data, pos);
                    Display();
                    break;
            case 4: DeleteAtFront();
                    Display();
                    break;
            case 5: DeleteAtEnd();
                    Display();
                    break;
            case 6: printf("\nEnter position : ");
                    scanf("%d", &pos);
                    DeleteAtPosition(pos);
                    Display();
                    break;
            case 7: printf("\nEnter data : ");
                    scanf("%d", &data);
                    pos = Search(data);
                    if(pos != -1)
                        printf("\nPosition : %d\n", pos);
                    else
                        printf("\nData Not Found!");
                    break;
            case 8: 
            default: printf("\nEnter valid choice!\n");
        }
    } while(choice != 6);
    return 0;
}