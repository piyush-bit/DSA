#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int inversePairs(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int mergeSortCountInversions(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int inversePairsV2(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int result = mergeSortCountInversions(arr, temp, 0, n - 1);
    free(temp);
    return result;
}

int mergeSortCountInversions(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += mergeSortCountInversions(arr, temp, left, mid);
        inv_count += mergeSortCountInversions(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int main() {
    // Open the CSV file to store results
    FILE* file = fopen("results.csv", "w");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    fprintf(file, "ArraySize,BruteForce,MergeAlgo\n");

    for (int n = 100; n <= 1000; n += 10) {
        int* arr1 = (int*)malloc(n * sizeof(int));
        int* arr2 = (int*)malloc(n * sizeof(int));

        if (arr1 == NULL || arr2 == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        // Generate random array
        for (int i = 0; i < n; i++) {
            arr1[i] = rand() % 10000; // Random values between 0 and 9999
            arr2[i] = arr1[i];
        }

        // Measure time for inversePairs
        clock_t start1 = clock();
        int count1 = inversePairs(arr1, n);
        clock_t end1 = clock();
        double time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;

        // Measure time for inversePairsV2
        clock_t start2 = clock();
        int count2 = inversePairsV2(arr2, n);
        clock_t end2 = clock();
        double time2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;

        // Write results to CSV
        fprintf(file, "%d,%f,%f\n", n, time1, time2);

        free(arr1);
        free(arr2);
    }

    fclose(file);
    return 0;
}
