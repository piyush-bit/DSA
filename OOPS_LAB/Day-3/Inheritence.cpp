//Wap to implement inheritence 

#include <iostream>
using namespace std;

class A
{
public:
    int x;
    A()
    {
        x = 0;
    }
};
class B : public A
{
public:
    int y;
    B()
    {
        y = 0;
    }
};
class C : public B
{
public:
    int z;
    C()
    {
        z = 0;
    }
};
int main()
{
    C c;
    c.x = 10;
    c.y = 20;
    c.z = 30;
    cout << c.x << " " << c.y << " " << c.z << endl;
    return 0;
}