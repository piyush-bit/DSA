//14. wap to override a function in herientance (it is also known as function overriding ) 

#include <iostream>
using namespace std;
class A
{
public:
    void fun()
    {
        cout << "fun of class A" << endl;
    }
};
class B : public A
{
public:
    void fun()
    {
        cout << "fun of class B" << endl;
    }
};
int main()
{
    B obj;
    obj.fun();
    return 0;
}