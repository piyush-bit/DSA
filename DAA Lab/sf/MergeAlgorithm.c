// merge two sorted algorithms
#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int arr2[], int n1, int n2 , int arr3[]){

    int i =0 ;
    int j =0 ;
    int k =0 ;

    int comparecount=0;

    while(i<n1 && j<n2){
        comparecount++;
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    while(i<n1){
        arr3[k++] = arr1[i++];
    }

    while(j<n2){
        arr3[k++] = arr2[j++];
    }
    printf("total comparission : %d \n",comparecount);
    return ;

}

int main (){
    int n1;
    printf("Enter the size of array 1:");
    scanf("%d",&n1);

    int* arr1 = (int*)malloc(n1 * sizeof(int));
    printf("Enter the elements of array 1:\n");
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }

    int n2;
    printf("Enter the size of array 2:");
    scanf("%d",&n2);

    int* arr2 = (int*)malloc(n2 * sizeof(int));
    printf("Enter the elements of array 2:\n");
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }

    int* arr3 = (int*)malloc((n1+n2) * sizeof(int));
    merge(arr1,arr2,n1,n2,arr3);
    printf("Merged array is:\n");
    for(int i=0;i<n1+n2;i++){
        printf("%d ",arr3[i]);
    }
    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}