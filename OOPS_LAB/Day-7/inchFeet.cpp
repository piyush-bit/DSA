#include <iostream>
using namespace std;
class feet;
class inch {
public:
    int x;

    inch() {
        x = 0;
    }

    
    inch& operator=(const feet &ob);


        void display() {
        cout << "inch = " << x << endl;
    }
};

class feet {
public:
    int x;

    feet() {
        x = 0;
    }

    
    feet& operator=(const inch& ob);

   
    void display() {
        cout << "feet = " << x << endl;
    }
};

inch& inch::operator=(const feet& ob) {
    x = ob.x * 12; 
    return *this;
}


feet& feet::operator=(const inch& ob) {
    x = ob.x / 12; 
    return *this;
}

int main() {
    inch ob1;
    feet ob2;

    cout << "Enter inch: ";
    cin >> ob1.x;

    
    ob2 = ob1;

    ob1.display();
    ob2.display();

    cout << "Enter feet: ";
    cin >> ob2.x;

    
    ob1 = ob2;

    ob1.display();
    ob2.display();

    return 0;
}
