#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int noofcomp=0;

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (1) {
        while (i <= high && arr[i] <= pivot){
            i++;
            noofcomp++;
        }
        while (j >= low && arr[j] > pivot){
            j--;
            noofcomp++;
        }
        if (i >= j)
            break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[low]);
    return j;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int kthsmall (int k , int* arr , int n ){
    int low =0 , high = n-1;
    while(low <= high){
        int pivot = partition(arr,low,high);
        printf("low : %d high: %d pivot :%d \n",low,high,pivot);
        if(pivot == k-1){
            return arr[pivot];
        }
        else if (pivot < k-1){
            low = pivot + 1;
        }else{
            high = pivot - 1;
        }
    }
    return -1; // kth smallest doesn't exist
}

int main(){
    int arr[100];
    int k = 0 ; 
    int n = 0 ; 
    printf("Enter the size of arr");
    scanf("%d",&n);
    printf("Enter the elements of array");
    for(int i =0 ; i<n ; i++){
        int t ;
        scanf("%d",&t);
        arr[i]=t;
    }
    // printf("Enter the k");
    // scanf("%d",&k);
    // quickSort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }

    // printf("%d is the %d smallest element",kthsmall(k,arr,n),k);

    quickSort(arr,0,n-1);
    printf("%d",noofcomp);
    return 0;
}