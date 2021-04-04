/*
Reverse given string using linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node     //Initialising linked list node
{
    char data;           //Data
    struct Node *next;  //Pointer to next node
};

void append(struct Node **head_ref, char new_data);      //Append node at end
void reverse(struct Node** head_ref);
void printList(struct Node *node);                      //Display list by traversing

int main()
{
    struct Node *head = NULL;   //Empty list
    char string[50];            //Initialize string
    printf("Enter String to reverse it: ");
    scanf("%s", string);
    printf("Entered String is %s\n", string);

    for (int i=0; string[i]!='\0'; i++) //append each character to linkedlist
    {
        append(&head, string[i]);
    }
    reverse(&head);                     //reverse the list
    printf("Reversed string is:\n");
    printList(head);
}

//Appends data to end
//Passing pointer to pointer of head so we can update head in the function
void append(struct Node **head_ref, char new_data)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref; /*temp pointer*/

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
			printf("%c", node->data);
			node = node->next;
		}
		printf("\n");
		return;
	}
}