/*
Create a Program to Implement Stack Operations: Push , Pop , Peek
*/

#include<stdio.h>

void push(char element, char stack[]);
void pop(char stack[]);
char peek(char stack[]);

int top = -1;       //Initially, top=-1
int size = 50;       //Max size of stack

void main() {
  char stack[size];     //Initialize Stack String

  short int choice;

  while(1)
  {
      printf("Enter your choice:\n");

      printf("1. Push Element in Stack\n");
      printf("2. Pop Element from Stack\n");
      printf("3. Peek Element from Stack\n");
      printf("4. Print Stack\n");
      printf("5. Exit\n");

      scanf("%hd", &choice);

      if(choice==1)
      {
          char e;
          printf("Enter element to push in Stack: ");
          scanf(" %c", &e);

          push(e, stack);
      }

      else if(choice==2)
      {
          pop(stack);
      }

      else if(choice==3)
      {
          printf("%c\n", peek(stack));
      }

      else if(choice==4)
      {
          for(int i=0; i<top+1; i++)
          {
              printf("%c\t", stack[i]);
          }
      }

      else if(choice==5)
      {
          break;
      }

      else
      continue;

  }
}

void push(char element, char stack[])   //Will add element to the stack
{
    if(top == size-1)
    printf("stack overflow\n");  
      
    else   
    {
        stack[++top]=element;
        printf("%c element added.\n",element);
    }
}

void pop(char stack[])      //Will remove last element added in Stack
{
    if(top == -1)
        printf("Underflow... Stack is empty\n");
    else  
        printf("%c element popped.\n",stack[top--]);
}

char peek(char stack[])     //Will return top element from stack
{
    if(top == -1)
    {
        printf("Underflow... Stack is empty\n");
        return -1;
    }
        
    else  
        return stack[top];
}