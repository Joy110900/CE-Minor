#include <stdio.h>
#include <stdlib.h>

# define size 100

void enqueue(); //Adds element to end of queue
void dequeue(); //Removes element from front of queue
void show();    //Displays queue

int arr[size];  //Initialising int queue
int rear = -1;
int front = -1;

void main()
{
    int ch;
    while (1)
    {
        printf("1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        } 
    } 
} 
  
void enqueue()
{
    int ele;
    if (rear == size - 1)       //Checking if queue is full
       printf("Overflow \n");

    else
    {
        if (front == - 1)       //If queue is empty, then set front as 0 as element is added now
            front = 0;
    
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &ele);
        rear++;                 //Increment so as to add element at end of queue
        arr[rear] = ele;        //Assign value to position
    }
} 
  
void dequeue()
{
    if (front == - 1 || front > rear)   //Checking if queue is empty
    {
        printf("Underflow \n");
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", arr[front]);
        front++;      //Incrementing front as an element is removed from front of queue
    }
} 
  
void show()
{
    if (front == - 1)       //Checking if queue is empty
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = front; i <= rear; i++) //Printing from front of array to back
            printf("%d ", arr[i]);
        printf("\n");
    }
} 