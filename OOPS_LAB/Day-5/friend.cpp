//1.wap a program to implement friend function to increment the private data member of a class by x given by the user . ( the x is last 4 digit of self registration number )

#include <iostream>
using namespace std;
class student{

    private:
        long rollno;
        int marks;
    public:
        friend void increment(student &s);
        void getdata(){
            cout<<"enter rollno and marks"<<endl;
            cin>>rollno>>marks;
        }
        void display(){
            cout<<"rollno="<<rollno<<endl<<"marks="<<marks<<endl;
        }
};

void increment(student &s){
    int x = s.rollno%10000;
    s.marks=s.marks+x;
};

int main(){

    student s;
    s.getdata();
    increment(s);
    s.display();
    return 0;
}