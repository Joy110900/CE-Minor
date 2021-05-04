/*
Implement Binary search operation on a given set of integers.
*/
#include <stdio.h>

int binary_search(int [], int, int, int);
void print_array(int arr[], int size);

void main()
{
    int key, index, n;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int sorted_arr[n];
    printf("\nEnter Sorted Array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &sorted_arr[i]);
    }

    printf("Entered Sorted Array is:\n");
    print_array(sorted_arr, n);

    printf("Enter key to search in array: ");
    scanf("%d", &key);

    index = binary_search(sorted_arr, 0, n-1, key);

    if(index == -1)
        printf("%d Element not found in the given array\n", key);

    else
        printf("%d Element found at index: %d\n", key, index);
}

//this function returns index of the key in array, if not found it returns -1
int binary_search(int arr[], int l, int r, int key)
{
    //middle element
    int index = l + (r-l)/2;
    if(l<=r)
    {
        if(arr[index] == key)
            return index;
        
        //search left side of array
        else if(arr[index] > key)
            binary_search(arr, l, index-1, key);

        //search right side of array
        else if(arr[index] < key)
            binary_search(arr, index+1, r, key);
    }

    //return -1 if key not found in array
    else
        return -1;
}

//function to print array
void print_array(int arr[], int size)
{
    for(int i=0; i<size; i++)
    printf("%d\t", arr[i]);
    printf("\n");
}