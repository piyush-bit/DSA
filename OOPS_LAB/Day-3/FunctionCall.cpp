// Q3 . Wap a program to impleament different function in a program such as 
//  (i).   function with no return type and an argument 
//  (ii).  function with no return tyoe and no argument 
//  (iii). function with return type and no argument 
//  (iv).  function with return type and an argument 


#include <iostream>
using namespace std;    

class TestDiffrentTypeOfFunctions {
    public:
    void function1(int x) {
        cout << "inside function1 with no return type and an argument" << endl;
        cout << "x= " << x << endl;
    }
    void function2() {
        cout << "inside function2 with no return type and no arguments" << endl;
    }
    int function3() {
        cout << "inside function3 with return type and no arguments" << endl;
        return 5;
    }
    int function4(int x) {
        cout << "inside function4 with return type and an argument" << endl;
        cout << "x= " << x << endl;
        return 5;
    }
};

int main() {
    TestDiffrentTypeOfFunctions obj;
    int x = 5;
    cout << "calling functions  " << x << endl;
    obj.function1(x);
    obj.function2();
    obj.function3();
    obj.function4(x);
    return 0;
}
