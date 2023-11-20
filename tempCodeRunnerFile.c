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