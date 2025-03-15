#include <iostream>
using namespace std;

void deleteElement(int a[], int n, int pos) {
    for (int i = pos; i < n-1; i++) {
        a[i] = a[i+1];
    }
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
    int pos;
    cout << "Enter the position of the element to be deleted: ";
    cin >> pos;
    deleteElement(arr, n, pos);
    cout << "Array after deletion: ";
    for (int i = 0; i < n-1; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
