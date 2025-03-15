#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int merge(int arr1[], int arr2[], int n1, int n2 , int arr3[]){

    int i =0 ;
    int j =0 ;
    int k =0 ;
    int count = 0;

    while(i<n1 && j<n2){
        count++;
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

    return count;

}

void mergeSort(int * arr  , int n ){

    if(n==1){
        return;
    }

    else{
        int* new_arr = (int*)malloc(n*sizeof(n));
        int mid = n/2;
        mergeSort(arr,mid);
        mergeSort(arr+mid,n-mid);
        merge(arr,arr+mid,mid,n-mid,new_arr);

        for(int i =0 ; i<n ;i++){
            arr[i]=new_arr[i];
        }
        free(new_arr);
    }
}
int mergeSortV2(int* arr, int n) {
    int comparissions = 0;
    int* temp = (int*)malloc(n * sizeof(int));

    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int mid = i + width - 1;
            int right = i + 2 * width - 1;
            if (mid >= n) break;
            if (right >= n) right = n - 1;

            int n1 = mid - i + 1;
            int n2 = right - mid;

            comparissions += merge(arr + i, arr + mid + 1, n1, n2, temp + i);

            for (int j = i; j <= right; j++) {
                arr[j] = temp[j];
            }
        }
    }

    free(temp);
    return comparissions;
}

int bubbleSort(int* arr, int n) {
    int comparissions = 0;
    for (int i = 0; i < n - 1; i++) {
        // Flag to track if any swapping happened in this iteration
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            comparissions++;
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1; // Mark as swapped
            }
        }

        // If no two elements were swapped, the array is sorted
        if (!swapped) {
            break;
        }
    }
    return comparissions;
}

int main() {
    FILE* fp = fopen("benchmark_results.csv", "w");
    if (!fp) {
        perror("Failed to create CSV file");
        return 1;
    }

    // Write CSV header
    fprintf(fp, "Array Size,Merge Sort (microseconds),Bubble Sort (microseconds)\n");

    int maxSize = 20000;
    for (int size = 1000; size <= maxSize; size += 100) {
        int* arr = (int*)malloc(size * sizeof(int));
        if (!arr) {
            perror("Memory allocation failed");
            fclose(fp);
            return 1;
        }

        // Fill the array with random values
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 100;
        }

        // copy the array to another array
        int* arr2 = (int*)malloc(size * sizeof(int));
        if (!arr2) {
            perror("Memory allocation failed");
            free(arr);
            fclose(fp);
            return 1;
        }
        for (int j = 0; j < size; j++) {
            arr2[j] = arr[j];
        }

        // Benchmark Merge Sort
        long long mergeSortTime = mergeSortV2(arr, size);

        // Benchmark Bubble Sort
        long long bubbleSortTime = bubbleSort(arr2, size);

        // Write the results to the CSV file
        fprintf(fp, "%d,%lld,%lld\n", size, mergeSortTime, bubbleSortTime);

        printf("Array Size: %d\n", size);

        // Free allocated memory
        free(arr);
    }

    fclose(fp);

    printf("Benchmark results written to benchmark_results.csv\n");
    return 0;
}