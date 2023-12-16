#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *newnode, *node, *first = NULL, *second = NULL, *last = NULL, *store = NULL;

struct Node* createNode(int arr[], int val) {
    int i;
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = arr[0];
    newnode -> next = NULL;
    last = newnode;
    for(i=1 ; i<val; i++) {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node -> data = arr[i];
        node -> next = NULL;
        last -> next = node;
        last = node;
    }
    return newnode;
}

void Concat(struct Node *first, struct Node *second) {
    store = first;
    while(store -> next != NULL) 
        store = store -> next;
    store -> next = second;
    second = NULL;
}

void Display(struct Node *ptr) {
    while(ptr != NULL) {
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main() {
    int len1, len2, i;
    printf("\nEnter length of First List : ");
    scanf("%d", &len1);
    printf("\nEnter length of Second List : ");
    scanf("%d", &len2);
    int arr1[len1] , arr2[len2];
    /*
    int *arr1 = (int*)malloc(len1 * sizeof(int));
    int *arr2 = (int*)malloc(len2 * sizeof(int));
    It is preferred to dynamically allocate memory at runtime but normally also working.
    */
    printf("\nEnter Elements in First List : \n");
    for(i=0 ; i<len1 ; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter Elements in Second List : \n");
    for(i=0 ; i<len2 ; i++) {
        scanf("%d", &arr2[i]);
    }
    first = createNode(arr1, len1);
    second = createNode(arr2, len2);
    printf("\nFirst List : ");
    Display(first);
    printf("\nSecond List : ");
    Display(second);
    Concat(first, second);
    printf("\nMerged Linked List : ");
    Display(first);
    return 0;
}