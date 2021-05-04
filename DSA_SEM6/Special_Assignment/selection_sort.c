/*
In an examination hall, students are waiting for their seating arrangement which has not yet been mailed.From the students unordered roll call list, faculty take the first number having lowest value and keep that value at index 1. It again finds the second lowest and keeps it index 2. Repeats the same process until all students are allocated a specific seat index. In order to design such a model, which takes student roll numbers and arranges them, what should be used and how. Implement the given model.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int [], int);
void print_array(int [], int);
void swap(int *, int *);

void main()
{
    //Initializing array 
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int rand_arr[n];

    /* //Initializing array randomly
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        rand_arr[i] = rand()%100;
    } */

    //Initializing array manually
    printf("\nEnter Roll Numbers of students:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &rand_arr[i]);
    }

    //Sorting Array using selection sort
    printf("---------Unsorted Array---------");
    print_array(rand_arr, n);
    selection_sort(rand_arr, n);
    printf("\n---------Sorted Array---------");
    print_array(rand_arr, n);    
    printf("\n---------Seating Arrangement---------\n");
    for(int i=0; i<n; i++)
    {
        printf("%d. %d\n", i+1, rand_arr[i]);
    }
}

//function to perform selection sort on given array
void selection_sort(int arr[], int n)
{
    int min;
    for(int i=0; i<n-1; i++)
    {
        printf("-------------Pass %d-------------\n", i+1);
        min = i;                                //Initially, min = first value of current array
        //Finding minimum value from the sub array
        for(int j=i+1; j<n; j++)               
            if(arr[j]<arr[min])
                min = j;
        printf("Min=%d\n", arr[min]);

        swap(&arr[i], &arr[min]);           //Swapping first value of current array with minimum value
        print_array(arr, n);
    }
}

//function to swap elements using pointer
void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

//function to print array
void print_array(int arr[], int size)
{
    printf("\n");
    for(int i=0; i<size; i++)
    printf("%d\t", arr[i]);
    printf("\n");
}