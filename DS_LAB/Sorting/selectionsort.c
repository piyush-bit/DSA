// implement selection sort 

#include <stdio.h>


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
        if(min_idx!=i){
            swap(&arr[min_idx], &arr[i]);
            printArray(arr, n);
        }
    }  
}  
  
int main()  
{  
    int arr[] = {1,3,5,4,2};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Unsorted array: \n");  
    printArray(arr, n);
    selectionSort(arr, n);  
    // printf("Sorted array: \n");  
    // printArray(arr, n);  
    return 0;  
}