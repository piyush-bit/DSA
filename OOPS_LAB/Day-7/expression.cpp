//8.wap to evalualte following expression (ob is object)
//    i. ob1=ob2+ob3/ob4
 //   ii. ob1=ob2*ob3-ob4

#include <iostream>
using namespace std;

class A{
    public:
    int x;
    A(){
        x=0;
    }
    A operator+(A ob){
        A temp;
        temp.x=x+ob.x;
        return temp;
    }
    A operator/(A ob){
        A temp;
        temp.x=x/ob.x;
        return temp;
    }
        A operator*(A ob){
        A temp;
        temp.x=x*ob.x;
        return temp;
    }
    A operator-(A ob){
        A temp;
        temp.x=x-ob.x;
        return temp;
    }
    void display(){
        cout<<x<<endl;
    }
};
int main(){
    A ob1,ob2,ob3,ob4;
    cin>>ob2.x>>ob3.x>>ob4.x;
    ob1=ob2+ob3/ob4;
    ob1.display();
    ob1=ob2*ob3-ob4;
    ob1.display();
    return 0;
}

