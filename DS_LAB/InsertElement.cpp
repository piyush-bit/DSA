#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index, value;
    cout << "Enter the index and value to be inserted: ";
    cin >> index >> value;
    if (index < 0 || index > n) {
        cout << "Invalid index" << endl;
        return 0;
    }
    n++;
    for (int i = n-1; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
