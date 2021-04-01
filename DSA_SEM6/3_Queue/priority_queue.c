/*
Write a program to implement priority queue using an linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node     //Initialising linked list node
{
    int data;           //Data
    struct Node *next;  //Pointer to next node
    int priority;       //Priority of queue
};

int size=0; //number of nodes

void enqueue(struct Node **head_ref, int new_data, int priority);
void dequeue(struct Node **head_ref);
void push(struct Node **head_ref, int new_data, int priority);    	//Insert node at head
void append(struct Node **head_ref, int new_data, int priority);      //Append node at end
void insertat(struct Node **head_ref, int pos, int new_data, int priority);	//Insert node at position
void delete_head(struct Node **head);			//Delete head node
void printPriorityQueue(struct Node *node);                      //Display list by traversing

void main()
{
    struct Node *head = NULL;   //Empty list
    int choice, new_data, priority;
    while(1)
    {
		printf("------------------------------\n");
		printf("Enter your choice:\n");
		printf("0. Exit\n");
		printf("1. Enqueue Priority Queue\n");
		printf("2. Dequeue Priority Queue\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				exit(0);

			case 1:
				printf("------------------------------\n");
				printf("Enque Operation\n");
				printf("------------------------------\n");
				printf("Enter new data\n");
				scanf("%d", &new_data);
				printf("Enter priority\n");
				scanf("%d", &priority);
				
				enqueue(&head, new_data, priority);
				printPriorityQueue(head);
				break;

			case 2:
				printf("------------------------------\n");
				printf("Dequeue Operation\n");
				printf("------------------------------\n");
				dequeue(&head);
				printPriorityQueue(head);
				break;
			
			default:
				break;
		}
    }
}

void enqueue(struct Node **head_ref, int new_data, int priority)
{
	struct Node *last = *head_ref; /*temp pointer*/
	int i=0;
	
	for(i=0; i<size; i++)				//Traversing through whole list
	{
		if(last->priority < priority)	//If new priority is higher than a nodes priority, break
			break;
		
		last = last->next;				//Next node
	}
	
	insertat(head_ref, i, new_data, priority);	//Insert new node according to priority
}

void dequeue(struct Node **head_ref)
{
	struct Node *last = *head_ref; /*temp pointer*/
	printf("%d Dequeued with Priority %d\n", last->data, last->priority);	
	delete_head(head_ref);			//Delete head node as that has the highest priority
}

//Appends data in beginning
//Passing pointer to pointer of head so we can update head in the function
void push(struct Node **head_ref, int new_data, int priority)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); //Initialize new node and assign memory

	new_node->data = new_data;      //Add data to new node
    new_node->priority = priority;

	new_node->next = (*head_ref);   //next of new node as head

	(*head_ref) = new_node;         //head points to new node
	size++; 
}

//Appends data to end
//Passing pointer to pointer of head so we can update head in the function
void append(struct Node **head_ref, int new_data, int priority)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref; /*temp pointer*/

	size++;

	new_node->data = new_data;	//add new data to node
    new_node->priority = priority;

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
void insertat(struct Node **head_ref, int pos, int new_data, int priority)
{
	if(pos<0 || pos>size)
	{
		printf("Cant add new node at this position\n");
		return;
	}
	
	else if(pos==0)			//If position is 0, then insert at beginning of list
	{
		push(head_ref, new_data, priority);
		return;
	}

	else if(pos==size)		//If position = size, then append at end of list
	{
		append(head_ref, new_data, priority);
		return;
	}

	else
	{
		size++;			//Increment size as new node is added
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); //Initialize new node and assign memory
		struct Node *nx = *head_ref, *pr; /*temp pointer*/

		new_node->data = new_data;
        new_node->priority = priority;

		for (int i = 0; i < pos; i++)
		{
			pr = nx;
			nx = nx->next;
		}

		pr->next = new_node;
		new_node->next = nx;
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

// This function prints contents of linked list starting from head to tail by traversing
void printPriorityQueue(struct Node *node)
{
	if (node == NULL)
	{
		printf("List is empty\n");
		return;
	}

	else
	{
        printf("\nList\tPriority\n");
		while (node != NULL)
		{
			printf("%d\t%d\n", node->data, node->priority);
			node = node->next;
		}
		return;
	}
}