#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int );
void AddAtFront(int );
void AddAtBack(int );
void AddAtPosition(int ,int );
void DeleteAtFront();
void DeleteAtBack();
void DeleteAtPosition(int );
int Search(int );
void SearchAndDelete(int );
struct Node* ReverseList(struct Node* );
void Display();
int count = 0, i = 0;

struct Node {
    int data;
    struct Node* next;
} *newnode, *list = NULL, *last = NULL, *temp = NULL, *store = NULL;

struct Node *createNode(int info) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    count++;
    newnode -> data = info;
    newnode -> next = NULL;
    return newnode;
}

int main() {
    int choice, data, pos, loc;
    do {
        printf("\nEnter choice\n1. Add At Front\n2. Add At Back\n3. Add At Position\n4. Delete At Front\n5. Delete At Back\n6. Delete At Position\n7. Search Data\n8. Search and Delete Data\n9. Reverse List\n10. Display\n11. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("\nEnter data : ");
                    scanf("%d", &data);
                    AddAtFront(data);
                    Display();
                    break;
            case 2: printf("\nEnter data : ");
                    scanf("%d", &data);
                    AddAtBack(data);
                    Display();
                    break;
            case 3: printf("\nEnter data : ");
                    scanf("%d", &data);
                    printf("\nEnter position to be added : ");
                    scanf("%d", &pos);
                    AddAtPosition(data, pos);
                    Display();
                    break;
            case 4: DeleteAtFront();
                    count--;    
                    Display();
                    break;
            case 5: DeleteAtBack();
                    count--;
                    Display();
                    break;   
            case 6: printf("\nEnter position to be deleted : ");
                    scanf("%d", &pos);
                    DeleteAtPosition(pos);
                    count--;
                    Display();
                    break;    
            case 7: printf("\nEnter data : ");
                    scanf("%d", &data);
                    loc = Search(data);
                    printf("\nData Found at Position %d\n", loc);
                    break; 
            case 8: printf("\nEnter data : ");
                    scanf("%d", &data);
                    SearchAndDelete(data);
                    count--;
                    Display();
                    break; 
            case 9: if(list != NULL) {
                        list = ReverseList(list);
                        printf("\nReversed List : \n");
                        Display();
                    }
                    else 
                        printf("List is Empty!");
                    break;
            case 10: Display();
                    break;
            case 11: exit(0);
                     break;
            default: printf("\nEnter a valid choice!");
        }
    }
    while(choice != 11);
    return 0;
}

void AddAtFront(int info) {
    newnode = createNode(info);
    if(list == NULL) 
        list = last = newnode;
    else {
        newnode -> next = list;
        list = newnode;
    }
}

void AddAtBack(int info) {
    newnode = createNode(info);
    if(list == NULL) 
        list = last = newnode;
    else {
        last -> next = newnode;
        last = newnode;
    }
}

void AddAtPosition(int info, int pos) {
    newnode = createNode(info);
    if(pos == 1)
        AddAtFront(info);
    else if(pos == (count+1))
        AddAtBack(info);
    else {
        temp = list;
        for(i=1 ; i<pos ; i++) {
            store = temp;
            temp = temp -> next;
        }
        store -> next = newnode;
        newnode -> next = temp; 
    }
}

void DeleteAtFront() {
    if(list == NULL)
        printf("\nList is Empty!");
    else {
        temp = list;
        printf("\nNode Deleted : %d\n", list -> data);
        list = list -> next;
        free(temp);
    }
}

void DeleteAtBack() {
    if(list == NULL) 
        printf("\nList is Empty!");
    else {
        temp = list;
        while(temp -> next != last) 
            temp = temp -> next;
        printf("\nNode Deleted : %d\n", last-> data);
        free(last);
        temp -> next = NULL;
        last = temp;
    }
}

void DeleteAtPosition(int pos) {
    if(pos == 1)
        DeleteAtFront();
    else if(pos == (count+1))
        DeleteAtBack();
    else {
        temp = list;
        for(i=1 ; i<pos; i++) {
            store = temp;
            temp = temp -> next;
        }
        printf("\nNode Deleted : %d\n", temp -> data);
        store -> next = temp -> next;
        free(temp);
    }
}

int Search(int info) {
    int pos = 1;
    if(list == NULL)
        printf("\nList is Empty!");
    else {
        temp = list;
        while(temp != NULL) {
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

struct Node* ReverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while(current != NULL) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void Display() {
    if(list == NULL) 
        printf("\nList is Empty!");
    else {
        temp = list;
        printf("\n");
        while(temp != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("\nTotal nodes : %d", count);
        printf("\n");
    }
}