struct Node *createNode(int array[], int val) {
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = array[0];
    newnode -> next = NULL;
    last = newnode;
    for(i=1 ; i<val ; i++) {
        node = (struct Node*)malloc(sizeof(struct Node));
        node -> data = array[i];
        node -> next = NULL;
        last -> next = node;
        last = node;
    }
    return newnode;
}

void Concat(struct Node *first, struct Node *second) {
    store = first;
    while(store != NULL)
        store = store -> next;
    store -> next = second;
    second = NULL;
}

struct Node *copyList(struct Node *source) {
    struct Node *copiedList = NULL;
    struct Node *lastCopied = NULL;
    struct Node *temp = source;
    while(temp != NULL){
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(copiedList == NULL) {
            copiedList = newnode;
            lastCopied = newnode;
        }
        else {
            lastCopied -> next = newnode;
            lastCopied = newnode;
        }
        temp = temp -> next;
    }
    return copiedList;
}