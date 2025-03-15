//7.wap to evaluate multiplication of two object using operator overloading 

#include <iostream>
using namespace std;
class A{
    public:
    int x,y;
    A(){
        x=y=0;
    }
    A operator*(A ob){
        A temp;
        temp.x=x*ob.x;
        temp.y=y*ob.y;
        return temp;
    }
    void display(){
        cout<<x<<" "<<y<<endl;
    }
};
int main(){
    A ob1,ob2,ob3;
    cin>>ob1.x>>ob1.y>>ob2.x>>ob2.y;
    ob3=ob1*ob2;
    ob3.display();
    return 0;
}