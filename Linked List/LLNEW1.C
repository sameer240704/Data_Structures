// Add Node, Copy List, Concatenate Two Lists, Split List, Reverse List

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;

} *current = NULL;

void displayList(struct Node* list);
struct Node* addNode(struct Node* list, int data);
struct Node* copyList(struct Node* source);
struct Node* concatenateTwoLists(struct Node* list1, struct Node* list2);
void splitList(struct Node* source, struct Node** front, struct Node** back);
struct Node* reverseList(struct Node* head);
int numberOfNodes(struct Node* head);

struct Node* createNode(int info) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = info;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* list = NULL;
    int data, choice;
    //clrscr();
	printf("Linked List => \n\n");
    do {
		printf("\n1. Add Node\n2. Concatenate Two Lists\n3. Split the List\n4. Count the Number of Nodes\n5. Reverse the List\n6. Copy the List\n7. Display the List\n8. Exit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice) {
				case 1:
					printf("Enter data : ");
					scanf("%d", &data);
					list = addNode(list, data);
					break;

				case 2 : if (list != NULL) {
							struct Node* list2 = NULL;
							printf("\nCreate a second list : \n");
							printf("Enter data for the new node : \n");
							while(1){
							scanf("%d", &data);
							if (data == 0)
								break;
							list2 = addNode(list2, data);
						}
						list = concatenateTwoLists(list, list2);					
					}
					else
						printf("\nList is empty");
					break;

				case 3 : if (list != NULL) {
							struct Node* front = NULL;
							struct Node* back = NULL;
							splitList(list, &front, &back);
							printf("Front of the List : \n");
							displayList(front);
							printf("\nBack of the List : \n");
							displayList(back);
						 }
						 else
							printf("\nList is empty");
						 break;
			
				case 4 : if (list != NULL) {
							int noOfNodes = numberOfNodes(list);
							printf("\nNumber of Nodes : %d", noOfNodes);
						 }
						 else
							printf("\nList is empty");
						 break;

				case 5 : if (list != NULL) {
							list = reverseList(list);
							printf("Reversed List : \n");
							displayList(list);
						 }
						 else
							printf("\nList is empty");
						 break;

				case 6 : if (list != NULL) {
							struct Node* copiedList = copyList(list);
							printf("\nCopied List : \n");
							displayList(copiedList);
						 }
						 else
							printf("\nList is empty");
						 break;

				case 7 : if (list != NULL)
							displayList(list);
						 else
							printf("\nList is empty");
						 break;
					

				case 8: exit(0);

				default: printf("\nPlease enter a valid number!!!");
			}
    } while (choice != 8);
    current = list;
    while (current != NULL) {
		struct Node* temp = current;
        current = current->next;
        free(temp);
    }
	list = NULL;
    getch();
    return 0;
}

struct Node* addNode(struct Node* list, int data) {
    struct Node* newNode = createNode(data);
    if (list == NULL)
		list = newNode;
    else {
		struct Node* current = list;
		while (current->next != NULL)
	    	current = current->next;
		current->next = newNode;
    }
    return list;
}

struct Node* concatenateTwoLists(struct Node* list1, struct Node* list2) {   
	struct Node* temp;
    if (list1 == NULL) 
		return list2;
    temp= list1;
    while (temp->next != NULL)
		temp = temp->next;
    temp->next = copyList(list2);
    return list1;
}

struct Node* copyList(struct Node* source) {
    struct Node* copiedList = NULL;
    struct Node* lastCopied = NULL;
    struct Node* temp = source;
    while (temp != NULL) {
		struct Node* newNode = createNode(temp->data);
		if (copiedList == NULL) {
		    copiedList = newNode;
		    lastCopied = newNode;
		}
		else {
	    	lastCopied->next = newNode;
	    	lastCopied = newNode;
		}
		temp = temp->next;
    }
    return copiedList;
}

void splitList(struct Node* source, struct Node** front, struct Node** back) {   
	struct Node* slow;
    struct Node* fast;
    if (source == NULL) {
		*front = NULL;
		*back = NULL;
		return;
    }
    if (source->next == NULL) {
		*front = source;
		*back = NULL;
		return;
    }
    slow = source;
    fast = source->next;
    while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
		    slow = slow->next;
	    	fast = fast->next;
		}
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
    }
    head = prev;
    return head;
}

int numberOfNodes(struct Node* head) {
    int counter = 0;
    struct Node* current = head;
    while (current != NULL) {
		counter++;
		current = current->next;
    }
    return counter;
}

void displayList(struct Node* list) {
    struct Node* current = list;
	printf("\n");
    while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
    }
    printf("NULL");
}