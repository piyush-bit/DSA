#include <iostream>
using namespace std;

void check_melody(int melody[], int n) {
    for(int i = 0; i < n-1; i++) {
        int gap = abs(melody[i+1] - melody[i]);
        if(!(gap == 5 || gap == 7)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t ;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int melody[n];
        for (int i = 0; i < n; i++) {
            cin >> melody[i];
        }   

        check_melody(melody, n);
    }
    return 0;
}