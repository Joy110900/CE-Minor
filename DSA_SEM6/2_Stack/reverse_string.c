/*
Reverse a given string using Stack
*/

#include <stdio.h>  
#include <string.h>

void push(char x, char stack[]);
void pop(char stack[]);

int top=-1, size=20;  

void main()  
{  
   char stack[size], str[20];   //Initialize stack and string
   fgets(str, 20, stdin);       //Scan input from user 
   int len = strlen(str);       //Length of string 
  
   for(int i=0;i<len;i++)       //Push string into stack
        push(str[i], stack);  
  
   for(int i=0;i<len;i++)       //Pop string from stack
      pop(stack);  
} 
  
void push(char x, char stack[])
{
    if(top == size-1)               //if stack is full
        printf("stack overflow\n");  
      
    else   
        stack[++top] = x;         //First increment top and then push x
}  
  
void pop(char stack[])
{  
    if(top == -1)               //if stack is empty
        printf("Underflow... Stack is empty\n");
    else  
        printf("%c",stack[top--]);      //return top element and decrement top
}