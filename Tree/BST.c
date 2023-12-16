#include<stdio.h>
#include<conio.h>
struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
} *root = NULL;

struct Node* insert(struct Node *r,int data)
{
	if (r==NULL)
	{
		r=(struct Node*)malloc(sizeof(struct Node));
		r->value=data;
		r->left=NULL;
		r->right=NULL;
	}
	else if(data<r->value)
		r->left=insert(r->left,data);
	else
		r->right=insert(r->right,data);
	return r;
}
void inOrder(struct Node *r)
{
	if(r!=NULL)
	{
		inOrder(r->left);
		printf("%d  ",r->value);
		inOrder(r->right);
	}
}

void preOrder(struct Node *r)
{
	if(r!=NULL)
	{
		printf("%d  ",r->value);
		preOrder(r->left);
		preOrder(r->right);
	}
}

void postOrder(struct Node *r)
{
	if(r!=NULL)
	{
		postOrder(r->left);
		postOrder(r->right);
		printf("%d  ",r->value);
	}
}
void search(struct Node *r,int data)
{
	if(r==NULL)
		printf("\nElement does not exist.");
	else if(data==r->value)
		printf("\nElement is present in the tree.");
	else if(data < r->value)
		 search(r->left,data);
	else
		 search(r->right,data);
}

struct Node *findMin(struct Node *r)
{
	if(r==NULL)
		return 0;
	else if(r->left==NULL)
		return r;
	else
		return(findMin(r->left));
}


struct Node *delete(struct Node *r,int data)
{
	struct Node *temp;
	if(r==NULL)
	{
		printf("\nTree is empty");
		return 0;
	}
	else if(data < r->value)
		r->left=delete(r->left,data);
	else if(data > r->value)
		r->right=delete(r->right,data);
	else if(r->left!=NULL && r->right!=NULL)
	{
		temp=findMin(r->right);
		r->value=temp->value;
		r->right=delete(r->right,r->value);
	}
	else
	{
		temp=r;
		if(r->left==NULL)
			r=r->right;
		else if (r->right==NULL)
		       r=r->left;
		free(temp);
	}
	return(r);
}

int count(struct Node *r)
{
	if(r==NULL)
		return 0;
	return (1 + count(r->left) + count(r->right));
}


int height(struct Node* r)
{
	int hgt_left,hgt_right;
	if(r==NULL)
		return 0;
	hgt_left = height(r->left);
	hgt_right = height(r->right);
	if(hgt_left>hgt_right)
		return (1+hgt_left);
	return (1+hgt_right);
}

void mirrorImg(struct Node* r)
{
	struct Node* temp;
	if(r!=NULL)
	{
		mirrorImg(r->left);
		mirrorImg(r->right);
		temp = r->left;
		r->left =r->right;
		r->right = temp;
	}
}

void main()
{
	int i,n,data,ch;
	root=NULL;
	//clrscr();
	do {
		printf("\nEnter a choice\n");
		printf("\nBinary Tree Traversal\n");
		printf("1] Enter a node\n2] Preorder Traversal\n3] Inorder Traversal\n4] Postorder Traversal\n5] Search\n6] Delete Node\n7] Count\n8] Height\n9]Mirror image\n10] Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter data: ");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2: printf("\nPreorder Traversal\n");
				preOrder(root);
				printf("\n");
				break;
			case 3: printf("\nInorder Traversal\n");
				inOrder(root);
				printf("\n");
				break;
			case 4: printf("\nPostorder Traversal\n");
				postOrder(root);
				printf("\n");
				break;
			case 5: printf("Enter the element you want to search: ");
				scanf("%d",&data);
				search(root,data);
				break;
			case 6: printf("Enter the element you want to delete: ");
				scanf("%d",&data);
				delete(root,data);
				break;
			case 7: printf("Count of the nodes is: %d",count(root));
				break;
			case 8: printf("Height of the tree is: %d",height(root));
				break;
			case 9: printf("\n Mirror image of Binary tree is:");
				mirrorImg(root);
				inOrder(root);
				break;
			case 10: exit(0);
				break;
			default: printf("\nWrong choice entered.");
		}
	} while(ch!=10);
	getch();
}