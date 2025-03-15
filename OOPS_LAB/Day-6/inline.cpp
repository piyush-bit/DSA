//4.wap to differentiate between a member function and a inline function

#include <iostream>
using namespace std;
class student
{
    long roll;
    int marks;
    public:
    void getdata()
    {
        cin>>roll>>marks;
    }

    inline void display();
       
};

inline void student::display()
{
    cout<<"rollno="<<roll<<endl<<"marks="<<marks<<endl;
}
int main()
{
    student s;
    s.getdata();
    s.display();
    return 0;
}