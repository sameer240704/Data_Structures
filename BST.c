#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
     int value;
     struct node* left;
     struct node* right;
} *root = NULL;

struct node* insert(struct node* r, int data);
void preOrder(struct node* r);
void inOrder(struct node* r);
void postOrder(struct node* r);
struct node* BinarySearch(struct node* r, int data);
struct node* delete(struct node* r, int data);
struct node* find_min(struct node *r);
int count(struct node* r);
int height(struct node* r);

int main()
{
    int i, n, v, choice;
    root = NULL;
    //clrscr();
    printf("\n***BINARY SEARCH TREE***");
    do {
        printf("\n1. Enter Node\n2. PreOrder Traversal\n3. InOrder Traversal\n4. PostOrder Traversal\n5.Search\n6. Delete a Node\n7. Number of nodes in the tree\n8. Height of the tree\n9. Exit");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice) {
                case 1: printf("\nEnter Data:");
                    scanf("%d", &v);
                    root = insert(root, v);
                    break;

                case 2: printf("\nPreorder Traversal:");
                    preOrder(root);
                    printf("\n");
                    break;

                case 3: printf("\nInorder Traversal:");
                    inOrder(root);
                    printf("\nMinimum:%d",find_min(root)->value);
                    break;
                
                case 4: printf("\nPostorder Traversal:");
                    postOrder(root);
                    printf("\n");
                    break;

                case 5: printf("\nEnter the data to be searched:");
                        scanf("%d", &v);
                        root = BinarySearch(root, v);
                        break;

                case 6: printf("Enter the data to be deleted:");
                        scanf("%d", &v);
                        root = delete(root, v);
                        break;

                case 7: printf("\nTotal number of nodes in the tree:%d",count(root));
                        break;

                case 8: printf("\nHeight of the tree:%d",height(root));
                        break;

                case 9: exit(0);

                default: printf("\nEnter a valid choice");
        }
    } while(choice !=9);
    getch();
    return 0;
}

struct node* insert(struct node* r, int data) {
    if(r==NULL) {
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if(data < r->value)
        r->left = insert(r->left, data);
    else 
        r->right = insert(r->right, data);
    return r;
}

void inOrder(struct node* r) {
    if(r!=NULL) {
        inOrder(r->left);
        printf("%d ", r->value);
        inOrder(r->right);
    }
}

void preOrder(struct node* r) {
    if(r!=NULL) {
        printf("%d ", r->value);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r) {
    if(r!=NULL) {
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->value);
    }
}

struct node* BinarySearch(struct node* r, int data) {
    if(r == NULL) {
        printf("Number doesn't exist");
    }
    else if(data == r->value) {
        printf("Item found");
        return r;
    }
    else if(data<r->value)
        return BinarySearch(r->left, data);
    else
        return BinarySearch(r->right, data);
    return 0;
}

struct node *find_min(struct node *r) {
    if(r == NULL)
        return 0;
    else if(r->left == NULL)
        return r;
    else
        return(find_min(r->left));
}

struct node* delete(struct node* r, int data) {
    struct node *temp;
    if (r == NULL) {
        printf("\nTree is Empty");
        return r;
    }
    if (data < r->value)
        r->left = delete(r->left, data);
    else if (data > r->value)
        r->right = delete(r->right, data);
    else {
        if (r->left == NULL) {
            temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL) {
            temp = r->left;
            free(r);
            return temp;
        }
        temp = find_min(r->right);
        r->value = temp->value;
        r->right = delete(r->right, temp->value);
    }

    return r;
}

int count(struct node* r) {
    if(r==NULL)
    return 0;
    return(1+count(r->left)+count(r->right));
}

int height(struct node* r) {
    int h_left;
    int h_right;
    if(r==NULL)
        return 0;
    h_left=height(r->left);
    h_right=height(r->right);
    if(h_left>h_right)
        return 1+h_left;
    return 1+h_right;
}