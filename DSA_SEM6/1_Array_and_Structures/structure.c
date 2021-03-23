/*
Create  an  array  of  structure  and  perform  insertion,  deletion  and update operation using pointers.
*/

#include <stdio.h>

struct person {         //Intialise Structure
    char name[20];
    int age;
};

void insert(struct person *, int pos);  //Insert new structure at given position
void update(struct person *, int pos);  //Update structure at given position
void delete(struct person *, int pos);  //Delete structure at given position
void print_struct(struct person *);     //Print structure

int n;

void main()
{
    struct person information[100];     //Initialise structure array, max size=100
    struct person *p;       // structure pointer
    p = information;        

    printf("Enter no. of persons:\n");
    scanf("%d", &n);

    printf("Enter %d persons information:\n", n);
    for(int i=0; i<n; i++)      
    {
        printf("Name: ");
        scanf("%s", (p+i)->name);
        printf("Age: ");
        scanf("%d", &(p+i)->age);
    }

    short int choice;       //Enter your choice for structure functions

    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Insert Element in Structure Array\n");
        printf("2. Update Element in Structure Array\n");
        printf("3. Delete Element from Structure Array\n");
        printf("4. Display Structure Array\n");
        printf("5. Exit\n");

        scanf("%hd", &choice);

        if (choice==1)
        {
            int data, pos;

            printf("\nPosition you want to insert in array: ");
            scanf("%d", &pos);

            insert(p, pos);
        }

        else if (choice==2)
        {
            int data, pos;

            printf("\nPosition you want to update in array: ");
            scanf("%d", &pos);

            update(p, pos);
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
            print_struct(p);
        }

        else if (choice==5)
            break;
        
        else
            continue;
    }
}

void print_struct(struct person *arr)
{
    for(int i=0; i<n; i++)
    {
        printf("----------------\n");
        printf("Name: %s\n", (arr+i)->name);
        printf("Age: %d\n", (arr+i)->age);
        printf("----------------\n");
    }
}

void delete(struct person *p, int pos)
{
    for(int i=0; i<n-pos; i++)      //Shifting whole array to left to delete element
    {
        *(p+pos+i) = *(p+pos+i+1);
    }
    n--;
    printf("\n-----Structure after Deletion------\n");
    print_struct(p);
}

void insert(struct person *p, int pos)  //Insert element at position
{
    printf("Enter person info:\n");
    printf("Name: ");
    scanf("%s", (p+pos)->name);
    printf("Age: ");
    scanf("%d", &(p+pos)->age);
    n++;
    printf("\n-----Structure after Inserting------\n");
    print_struct(p);
}

void update(struct person *p, int pos)      //Update structure element
{
    printf("Enter new name and age\n");
    printf("Name: ");
    scanf("%s", (p+pos)->name);
    printf("Age: ");
    scanf("%d", &(p+pos)->age);
    printf("\n-----Structure after Updating------\n");
    print_struct(p);
}