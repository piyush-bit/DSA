//2.wap a program to exchange value between the clases using friend function

#include <iostream>
using namespace std;
class student{

    private:
        int rollno;
        int marks;
    public:
        friend void exchange(student &s1,student &s2);
        void getdata(){
            cout<<"enter rollno and marks"<<endl;
            cin>>rollno>>marks;
        }
        void display(){
            cout<<"rollno="<<rollno<<"  "<<"marks="<<marks<<endl;
        }
};

void exchange(student &s1,student &s2){
    int temp;
    temp=s1.rollno;
    s1.rollno=s2.rollno;
    s2.rollno=temp;

    temp=s1.marks;
    s1.marks=s2.marks;
    s2.marks=temp;
};

int main(){

    student s1,s2;
    s1.getdata();
    s2.getdata();
    exchange(s1,s2);
    s1.display();
    s2.display();
    return 0;
}