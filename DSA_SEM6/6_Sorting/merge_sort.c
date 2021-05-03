/*
Write a program to implement merge sort for sorting a given set of integers in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
void print_array(int arr[], int size);

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

    //Sorting using merge sort
    printf("Unsorted Array");
    print_array(rand_arr, n);
    merge_sort(rand_arr, 0, n-1);
    printf("Sorted Array");
    print_array(rand_arr, n);
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//sub arrays
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	//merge the sub arrays
	i = 0; 	//left sub array first index
	j = 0; 	//right sub array first index
	k = l;	//merged array first index

	while (i < n1 && j < n2) //loop until end of array
	{
		if (L[i] <= R[j]) 		//if left subarray elem is smaller, add it to final array
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//copying left out element from left subarray to array
	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	//copying left out element from right subarray to array
	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

//l -> left index of sub array
//r -> right index of sub array
void merge_sort(int arr[], int l, int r)
{
	if (l < r) 
    {
		//Same as (l+r)/2, but avoids overflow for
		//large l and h
        //middle index of sub array
		int m = l + (r - l) / 2;

		//Sort first and second halves
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

//function to print array
void print_array(int arr[], int size)
{
    printf("\n");
    for(int i=0; i<size; i++)
    printf("%d\t", arr[i]);
    printf("\n");
}