/*
Write a program to implement singly Linked List’s operation-Insertion, Deletion and Traversal.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node     //Initialising linked list node
{
    int data;           //Data
    struct Node *next;  //Pointer to next node
};

int size=0; //number of nodes

void push(struct Node **head_ref, int new_data);    	//Insert node at head
void append(struct Node **head_ref, int new_data);      //Append node at end
void insertat(struct Node **head_ref, int pos, int new_data);	//Insert node at position
void delete_last(struct Node **head_ref);		//Delete last node
void delete_head(struct Node **head);			//Delete head node
void delete_at(struct Node **head, int pos);	//Delete at position
void reverse(struct Node** head_ref);
void printList(struct Node *node);                      //Display list by traversing

int main()
{
    struct Node *head = NULL;   //Empty list

	short int choice;
	int el, pos;

	while(1)
	{
		printf("1. Insert node at beginning of list\n");
		printf("2. Insert node at end of list\n");
		printf("3. Insert node at position\n");
		printf("4. Delete last node\n");
		printf("5. Delete head node\n");
		printf("6. Delete node at a given position\n");
		printf("7. Reverse the list\n");
		printf("8. Print List\n");
		printf("9. Exit\n");
		printf("Enter you choice:\n");
		scanf("%hd", &choice);

		switch(choice)
		{
			case 1: 
				printf("--------------------------------\n");
				printf("New Data at front of list\n");
				printf("--------------------------------\n");
				printf("Enter new element\n");
				scanf("%d", &el);
				push(&head, el);
				printList(head);
				break;

			case 2:
				printf("--------------------------------\n");
				printf("New Data at end of list\n");
				printf("--------------------------------\n");
				printf("Enter new element\n");
				scanf("%d", &el);
				append(&head, el);
				printList(head);
				break;

			case 3:
				printf("--------------------------------\n");
				printf("New Data at given position\n");
				printf("--------------------------------\n");
				printf("Enter new element\n");
				scanf("%d", &el);
				printf("Enter position\n");
				scanf("%d", &pos);
				insertat(&head, pos, el);
				printList(head);
				break;

			case 4:
				printf("--------------------------------\n");
				printf("Delete last element\n");
				printf("--------------------------------\n");
				delete_last(&head);
				printList(head);
				break;

			case 5:
				printf("--------------------------------\n");
				printf("Delete first element\n");
				printf("--------------------------------\n");
				delete_head(&head);
				printList(head);
				break;

			case 6:
				printf("--------------------------------\n");
				printf("Delete element at given position\n");
				printf("--------------------------------\n");
				printf("Enter position you want to delete\n");
				scanf("%d", &pos);
				delete_at(&head, pos);
				printList(head);
				break;

			case 7:
				printf("--------------------------------\n");
				printf("Reverse given list\n");
				printf("--------------------------------\n");
				reverse(&head);
				printList(head);
				break;

			case 8:
				printList(head);
				break;

			case 9:
				exit(0);			//Exit Program after success run

			default:
				break;
		}

	}
}

//Appends data in beginning
//Passing pointer to pointer of head so we can update head in the function
void push(struct Node **head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); //Initialize new node and assign memory

	new_node->data = new_data;      //Add data to new node

	new_node->next = (*head_ref);   //next of new node as head

	(*head_ref) = new_node;         //head points to new node
	size++; 
}

//Appends data to end
//Passing pointer to pointer of head so we can update head in the function
void append(struct Node **head_ref, int new_data)
{
	printf("--------------------------------\n");
	printf("New Data at end of list\n");
	printf("--------------------------------\n");
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref; /*temp pointer*/

	size++;

	new_node->data = new_data;	//add new data to node

	new_node->next = NULL;		//new nodes next = null as it will be last node

	if (*head_ref == NULL)	//if list is empty, then head will point to new node
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)		//get last nodes next by traversing
		last = last->next;

	last->next = new_node;			//last nodes next will point to new node
}

//Inserts data at the given position
void insertat(struct Node **head_ref, int pos, int new_data)
{
	if(pos<0 || pos>size)
	{
		printf("Cant add new node at this position\n");
		return;
	}
	
	else if(pos==0)
	{
		push(head_ref, new_data);
		return;
	}

	else if(pos==0)
	{
		push(head_ref, new_data);
		return;
	}

	else
	{
		size++;
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); //Initialize new node and assign memory
		struct Node *nx = *head_ref, *pr; /*temp pointer*/

		new_node->data = new_data;

		for (int i = 0; i < pos; i++)	//store the previous and new node
		{
			pr = nx;
			nx = nx->next;
		}

		pr->next = new_node;		//previous node will point at new node
		new_node->next = nx;		//new node will point at next node
	}
}

void delete_last(struct Node **head_ref)
{
	if(size==0)
	{
		printf("Linked list is empty\n");
		return;
	}
	
	else
	{
		size--;
		struct Node *last = *head_ref, *pr;
		while(last->next != NULL)
		{
			pr = last;
			last = last->next;
		}
		free(last);
		pr->next = NULL;
	}
}

void delete_head(struct Node **head_ref)
{
	if(size==0)
	{
		printf("List is empty\n");
		return;
	}

	else
	{
		size--;
		struct Node *last = *head_ref;
		*head_ref = last->next;
		free(last);
	}
}

void delete_at(struct Node **head_ref, int pos)
{
	if(pos<0 || pos>size || pos==0)
	{
		printf("Node does not exist at this poistion\n");
		return;
	}

	else
	{
		size--;
		
		struct Node *nx = *head_ref, *pr; /*temp pointer*/

		for (int i = 0; i < pos; i++)
		{
			pr = nx;
			nx = nx->next;
		}
		nx = nx->next;
		pr->next = nx;
	}

}

void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL, *current = *head_ref, *next = NULL;
    
    while (current != NULL) 
	{
        next = current->next;
 
        current->next = prev;
 
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// This function prints contents of linked list starting from head to tail by traversing
void printList(struct Node *node)
{
	printf("--------------------------------\n");
	printf("Singly linked list\n");
	printf("--------------------------------\n");
	if (node == NULL)
	{
		printf("List is empty\n");
		return;
	}

	else
	{
		printf("\n");
		while (node != NULL)
		{
			printf("%d->", node->data);
			node = node->next;
		}
		printf("NULL\n");
		return;
	}
}