/*
Checking if the input brackets are properly closed or not.
*/

#include <stdio.h>
#include <string.h>

int top = -1;

void push(char element, char stack[]);
char pop(char stack[]);
int check_brackets(char s[], int len);
char get_reversed_brackets(char b);
char peek_top(char stack[]);
void print_stack(char stack[]);

void main()
{
    char ip[20];
    fgets(ip, 20, stdin);       //Scan input from user     

    if(check_brackets(ip, strlen(ip))==1)
        printf("Entered brackets are closed properly\n");

    else
        printf("Entered brackets are not closed properly\n");
}

int check_brackets(char s[], int len)
{
    char stack[50];

    for(int i=0; i<len-1; i++)
    {
        if(top == -1)           //If stack is empty
            push(s[i], stack);

        else
        {
            if(peek_top(stack) == get_reversed_brackets(s[i]))
                pop(stack);

            else
                push(s[i], stack);
        }
    }

    if(top == -1)
        return 1;

    else
        return 0;
}

char get_reversed_brackets(char b)
{
    switch (b)
    {
        case '(':
            return ')';
            break;

        case ')':
            return '(';
            break;

        case '{':
            return '}';
            break;

        case '}':
            return '{';
            break;

        case '[':
            return ']';
            break;

        case ']':
            return '[';
            break;

        default:
            break;
    }
}

void push(char element, char stack[])
{
    stack[++top] = element;
}

char pop(char stack[])
{
    if (top == -1)
        return 'E';

    else
        return stack[top--];
}

char peek_top(char stack[])
{
    if (top == -1)
        return 'E';

    else
        return stack[top];
}

void print_stack(char stack[])
{
    for(int i=0; i<top+1; i++)
        printf("%c\t", stack[i]);
    printf("\n");
}