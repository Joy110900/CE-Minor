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

    //Sorting using quick sort
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

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
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