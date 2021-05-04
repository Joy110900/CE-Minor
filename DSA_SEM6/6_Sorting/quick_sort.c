/*
Write a program to implement Quick sort for sorting a given set of integers in ascending order. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int [], int, int);
void swap(int *, int *);
void print_array(int [], int);
int partition(int [], int, int);


void main()
{
    //Initializing array to sort with random numbers
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int rand_arr[n];
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        rand_arr[i] = rand()%100;
    }

    //Sorting using quick sort
    printf("Unsorted Array\n");
    print_array(rand_arr, n);
    quick_sort(rand_arr, 0, n-1);
    printf("Sorted Array\n");
    print_array(rand_arr, n);    
}

//function to quick sort an array in ascending order
void quick_sort(int arr[], int l, int h) 
{
    if (l < h) 
    {
        //get partition such that all elements left of it are less than it
        //all elements right of pivot are greater than it
        int part = partition(arr, l, h);

        //quick sorting left side of partition
        quick_sort(arr, l, part - 1);

        //quick sorting right side of partition
        quick_sort(arr, part + 1, h);
    }
}

// function to find the partition position
int partition(int arr[], int l, int h) 
{
    //last element as pivot, i is pointing to the greater element
    int pivot=h, i=l-1;

    //traversing through whole array
    for (int j=l; j<h; j++) 
    {
        //if current element is less than pivot
        if (arr[j] <= arr[pivot]) 
        {
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&arr[i], &arr[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&arr[i + 1], &arr[h]);

    // return the partition point
    return (i + 1);
}

//function to swap elements using pointer
void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

//function to print array
void print_array(int arr[], int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
    printf("%d\t", arr[i]);
    printf("\n");
}