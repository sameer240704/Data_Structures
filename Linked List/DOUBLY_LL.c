#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *prev,*next;
} *list=NULL,*last=NULL,*temp,*p,*q,*node;
int count=0,pos,i;
struct Node* createNode(int info) {
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=info;
    node->next=NULL;
    node->prev=NULL;
    count++;
    return node;
}

void addAtBegin(int info) {
    node=createNode(info);
    if(list==NULL)
		list=last=node;
    else {
		node->next=list;
		list->prev=node;
		list=node;
    }
}

void addAtEnd(int info) {
    node=createNode(info);
    if(list==NULL)
		list=last=node;
    else {
		last->next=node;
		node->prev=last;
		last=node;
    }
}

void deleteAtBegin() {
    if(list==NULL)
		printf("\nList is Empty!");
    else {
		temp=list;
		list=list->next;
		list->prev=NULL;
		free(temp);
		count--;
    }
}

void deleteAtEnd() {
    if(list==NULL)
		printf("\nList is Empty.");
    else {
		temp=last;
		last=last->prev;
		last->next=NULL;
		free(temp);
		count--;
    }
}
void insertAtPosition(int info) {
    node=createNode(info);
    printf("\nEnter position:");
    scanf("%d",&pos);
    if(pos==1)
	    addAtBegin(info);
    else if(pos==(count+1))
	    addAtEnd(info);
    else {
	    temp=list;
	    for(i=1;i<pos;i++) {
			p=temp;
			temp=temp->next;
	    }
	    p->next=node;
		temp->prev=node;
		node->prev=p;
	    node->next=temp;
    }
}

void deleteAtPosition(int pos1) {
    if(pos1==1)
	    deleteAtBegin();
    else if(pos1==(count+1))
	    deleteAtEnd();
    else if(pos1>count)
		printf("\nPosition exceeds total number of nodes!");
    else {
	    temp=list;
	    for(i=1;i<pos1;i++) {
			p=temp;
			temp=temp->next;
	    }
		q=temp->next;
		p->next=q;
		q->prev=p;
	    printf("\nNode data %d deleted.",temp->data);
	    free(temp);
		count--;
    }
}

int searchPosition(int info) {
    int ctr=0;
    if(list==NULL)
	    return 0;
    else {
	    temp=list;
	    pos=1;
	    while(temp!=NULL) {
			if(temp->data==info) {
				ctr++;
				break;
			}
			else {
				temp=temp->next;
				pos++;
			}
	    }
	    if(ctr!=0)
			return pos;
	    else
			return 0;
    }
}

void search_delete(int info) {
    int location=searchPosition(info);
    if(location!=0)
	    deleteAtPosition(location);
    else
	    printf("\nNode NOT found.");
}

void insertAfterData(int info) {
    int ctr=0,data1;
    printf("Enter data input:");
    scanf("%d",&data1);
    node=createNode(data1);
    temp=list;
    while(temp!=NULL) {
		if(temp->data==info) {
	    	p=temp;
	    	temp=temp->next;
	    	ctr++;
	    	break;
		}
		else {
	    	p=temp;
	    	temp=temp->next;
		}
    }
    if(ctr!=0) {
		p->next=node;
		temp->prev=node;
		node->next=temp;
		node->prev=p;
    }
    else
		printf("\nData Not Found!");
}

void displayF()
{
    if(list==NULL)
		printf("\nList is Empty!");
    else {
		temp=list;
		printf("\nDouble Linked List : \n");
		while(temp!=NULL) {
		    if(temp->next==NULL)
				printf("%d",temp->data);
	    	else
				printf("%d -> ",temp->data);
		    temp=temp->next;
		}	
	}
}

void displayB()
{
    if(list==NULL)
	printf("\nList is Empty!");
    else {
		temp=last;
		printf("\nDouble Linked List : \n");
		while(temp!=NULL) {
	    	if(temp->prev==NULL)
				printf("%d",temp->data);
	    	else
				printf("%d -> ",temp->data);
	    	temp=temp->prev;
		}
    }
}

int main() {
    int choice=0,d,po;
    printf("***Double Linked List Operations***");
    do {
        printf("\n1.Add At Begin\n2.Add At End\n3.Delete At Begin\n4.Delete At End\n5.Insert At Position\n6.Delete At Position\n7.Search Position\n8.Search and Delete\n9.Insert After Data\n10.Display Forward List\n11.Display Backward List\n12.Exit");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter data : ");
                    scanf("%d",&d);
                    addAtBegin(d);
                    break;
            case 2: printf("Enter data : ");
                    scanf("%d",&d);
                    addAtEnd(d);
                    break;
            case 3: deleteAtBegin();break;
            case 4: deleteAtEnd();break;
            case 5: printf("Enter data : ");
                    scanf("%d",&d);
                    insertAtPosition(d);
                    break;
            case 6: printf("Enter Position : ");
                    scanf("%d",&po);
                    deleteAtPosition(po);
                    break;
            case 7: printf("Enter data : ");
                    scanf("%d",&d);
		            po=searchPosition(d);
		            if(po!=0)
		            printf("\nPosition : %d",po);
		            else
		            printf("\nNode Not Found");
		            break;
	    	case 8: printf("Enter data : ");
		    	    scanf("%d",&d);
			        search_delete(d);
		        	break;
	    	case 9: printf("Enter data to search : ");
            	    scanf("%d",&d); 
                	insertAfterData(d);
	                break;
    	    case 10:displayF();
        	            break;
        	case 11:displayB();
            	        break;
	        case 12:exit(0);
    	    default:printf("Enter a valid choice");
        }
    } while(choice!=12);
    return 0;
}