#include <stdio.h>
#include <stdlib.h>

// Structure to store activity details
typedef struct {
    int start, finish;
} Activity;

// Comparison function to sort activities by finish time
int compare(const void *a, const void *b) {
    return ((Activity*)a)->finish - ((Activity*)b)->finish;
}

// Function to select the maximum number of activities
void activitySelection(Activity arr[], int n) {
    // Sort activities based on finish time
    qsort(arr, n, sizeof(Activity), compare);

    printf("Selected activities: \n");
    
    // The first activity always gets selected
    int lastSelected = 0;
    printf("(%d, %d)\n", arr[lastSelected].start, arr[lastSelected].finish);

    // Consider the rest of the activities
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= arr[lastSelected].finish) {
            printf("(%d, %d)\n", arr[i].start, arr[i].finish);
            lastSelected = i; // Update last selected activity
        }
    }
}

// Driver function
int main() {
    Activity activities[] = {{1, 3}, {2, 5}, {3, 9}, {6, 8}, {5, 7}};
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);
    return 0;
}
