// 13. wap to to implement hybrid inheritence and demonstrate the use of virtual class to avoid ambiguity problem .

#include <iostream>
using namespace std;
class A
{
public:
    int a;
    void fun1()
    {
        cout << "a" << endl;
    }
};
class B
{
public:
    int b;
    void fun2()
    {
        cout << "b" << endl;
    }
};
class C : virtual public A
{
public:
    int c;
    void fun3()
    {
        cout << "c" << endl;
    }
};
class D : virtual public B
{
public:
    int d;
    void fun4()
    {
        cout << "d" << endl;
    }
};
class E : public C, public D
{
public:
    int e;
    void fun5()
    {
        cout << "e" << endl;
    }
};
int main()
{
    E obj;
    obj.a = 1;
    obj.b = 2;
    obj.c = 3;
    obj.d = 4;
    obj.e = 5;
    obj.fun1();
    obj.fun2();
    obj.fun3();
    obj.fun4(); 
    obj.fun5();
    return 0;
}