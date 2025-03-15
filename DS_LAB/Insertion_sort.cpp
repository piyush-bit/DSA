//sort an array using inssertion sort 
#include <iostream>
using namespace std ; 

void printArr(int arr[] , int n){

        for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
        }
        cout <<endl;

}

int insertionSort(int arr[], int n) {
    int count = 0 ; 
    cout << "Steps : " << endl;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            count++;
            j--;
        }
        count++;
        arr[j + 1] = key;
        printArr(arr,n);
    }
    return count;
}





int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparission = insertionSort(arr, n);
    cout << "Number of comparissions: " << comparission << endl;
    cout << "Sorted array: ";
    printArr(arr, n); 
    return 0;
}
