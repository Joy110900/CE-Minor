/*
Create a two dimensional array and perform insertion, deletion and update operation using pointer.
*/

#include <stdio.h>

int r, c, size; 

void insert(int *, int data, int pos);  //Function to insert element
void print_array(int *);                //Function to print array
void update(int*, int data, int pos);   //Function to update element
void delete(int *, int pos);            //Function to delete element

void main(void)
{
    int arr[10][10];        //Initialize Array
    int *p = &arr[0][0];    //Initialising pointer

    printf("Enter number of rows: ");
    scanf("%d", &r);

    printf("Enter number of columns: ");
    scanf("%d", &c);

    size = r * c;           //Calculating size of array

    printf("Enter array elements.\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &*(p + i));
    }
    printf("Entered array is:\n");
    print_array(p);

    short int choice;

    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Insert Element in Array\n");
        printf("2. Update Element in Array\n");
        printf("3. Delete Element in Array\n");
        printf("4. Display array elements\n");
        printf("5. Exit\n");

        scanf("%hd", &choice);

        if (choice==1)
        {
            int data, pos;
            printf("Element you want to insert: ");
            scanf("%d", &data);

            printf("\nPosition you want to insert in array: ");
            scanf("%d", &pos);

            insert(p, data, pos);
        }

        else if (choice==2)
        {
            int data, pos;
            printf("New element: ");
            scanf("%d", &data);

            printf("\nPosition you want to update in array: ");
            scanf("%d", &pos);

            update(p, data, pos);
        }

        else if (choice==3)
        {
            int pos;

            printf("\nPosition you want to delete element in array: ");
            scanf("%d", &pos);

            delete(p, pos);
        }

        else if (choice==4)
        {
            print_array(p);
        }

        else if (choice==5)
            break;
        
        else
            continue;
    }
}

void insert(int *arr, int data, int pos)
{
    *(arr + pos) = data;
    size += 1;          //Incresing size as element is added
    r = (size/c)+1;     //Changing no. of rows
}

void print_array(int *arr)
{
    printf("Array elements are:\n");

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d\t", *((arr+i*c) + j));
        }
        printf("\n");
    }
}

void update(int *arr, int data, int pos)
{
    *(arr + pos) = data;        //Updating element at given position
    printf("Updated Array:\n");
    print_array(arr);
}

void delete(int *arr, int pos)
{
    for(int i=0; i<size-pos; i++)           //Shifting whole array to left from the element deleted
    {
        *(arr + pos + i) = *(arr + pos + i + 1);
    }
    printf("Updated Array after deleting elemet %d:\n", pos);
    print_array(arr);
    size -= 1;                  //Updating Size as element is deleted
    r = size/c;
}