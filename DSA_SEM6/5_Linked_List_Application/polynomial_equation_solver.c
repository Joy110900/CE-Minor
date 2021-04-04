/*
List application implement an addition of two polynomial equations using linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int pow;
    int coeff;
    struct Node *next;
};

void append(struct Node **head_ref, int pow, int coeff);                        //Append node at end
void add_element(struct Node **head_ref);                                       //Add elements to equation
void add_poly(struct Node **poly1, struct Node **poly2, struct Node **answer);  //add 2 polynomial equations
void printequations(struct Node *head_ref);                                     //Print equation

void main()
{
    struct Node *poly1=NULL, *poly2=NULL, *answer=NULL; //Initialize each list
    
    printf("Enter First Polynomial Equation\n");        //add elements to first equation
    add_element(&poly1);
    printequations(poly1);

    printf("Enter Second Polynomial Equation\n");       //add elements to second equation
    add_element(&poly2);
    printequations(poly2);

    printf("------------------------\n");
    printf("Addition of 2 Polynomial Equations:\n");

    add_poly(&poly1, &poly2, &answer);                  //add 2 polynomials and store the answer in answer node
    printequations(answer);
}

//Add elements to equation
void add_element(struct Node **head_ref)
{
    int choice, pow, coeff;
    while(1)
    {
        printf("Enter 0 to exit, else enter 1\n");
        scanf("%d", &choice);
        if(choice==0)
        {
            break;
        }
        struct Node *last = *head_ref;
        int j=0;
        printf("--------------------------------\n");
        printf("Enter Coefficient: ");
        scanf("%d", &coeff);
        printf("Enter Power: ");
        scanf("%d", &pow);
        printf("--------------------------------\n");
        while(last != NULL)             //Checking if entered power is already present in the equation, if so then update its coefficient by adding both old and new coefficients
        {
            if(pow == last->pow)                        //If the power already exists, add their coeff
            {
                last->coeff += coeff;
                j++;
                break;
            }
            last = last->next;
        }
        if(j==0)
        {
            append(head_ref, pow, coeff);               //If the power does not exist, then add new node to the equation
        }
    }
}

//adds 2 polynomial equations and stores the answer in answer structure
void add_poly(struct Node **poly1, struct Node **poly2, struct Node **answer)
{
    struct Node *p1 = *poly1, *p2=*poly2;
    int i=0;
    while(p1 != NULL)                                   //Traversing till end of first polynomial
    {
        i=0;
        p2 = *poly2;                                    //p2 pointing at head of second polynomial
        while(p2 != NULL)                               //Traversing till end of second polynomial
        {
            if(p1->pow==p2->pow)                        //If power is equal
            {
                append(answer, p1->pow, p1->coeff+p2->coeff);   //if p1 and p2 powers are same, add new node in answer with the same power and coefficient as the sum of the two nodes
                i++;                                    //Incrementing to indicate element is already appended
                break;
            }
            p2 = p2->next;
        }
        if(i==0)        //If powers are not equal, then append power and coefficient to the answer list 
        {
            append(answer, p1->pow, p1->coeff);
        }
        p1 = p1->next;
    }
    p2 = *poly2;
    p1 = *answer;

    //Iterating second polynomial over answer polynomial to add remaining powers to the answer list
    while(p2 != NULL)
    {
        i = 0;
        p1 = *answer;
        while(p1 != NULL)
        {
            if(p2->pow==p1->pow)
            {
                i++;
                break;
            }
            p1 = p1->next;
        }
        if(i==0)
        {
            append(answer, p2->pow, p2->coeff);
        }
        p2 = p2->next;
    }
}

//Appends data to end
//Passing pointer to pointer of head so we can update head in the function
void append(struct Node **head_ref, int pow, int coeff)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref; /*temp pointer*/

	new_node->pow = pow;	    //add new power to node
    new_node->coeff = coeff;	//add coeff to node

	new_node->next = NULL;		//new nodes next = null as it will be last node

	if (*head_ref == NULL)  	//if list is empty, then head will point to new node
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)		//get last nodes next by traversing
		last = last->next;

	last->next = new_node;			//last nodes next will point to new node
}

//Printing Equation
void printequations(struct Node *node)
{
    if (node == NULL)               //If the list is empty
	{
		printf("List is empty\n");
		return;
	}

	else
	{
		printf("\n");
		while (node != NULL)
		{
			printf("%dx^%d\t+\t", node->coeff, node->pow);
			node = node->next;
		}
		printf("0\n");
		return;
	}
}