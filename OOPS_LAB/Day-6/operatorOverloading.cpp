//6.wap to implemarnt -- prefix and postfix operation using opereator overloading

#include <iostream>
using namespace std;
class student
{
    int roll;
    int marks;
    public:
    void getdata()
    {
        cin>>roll>>marks;
    }

    void display()
    {
        cout<<"rollno="<<roll<<" "<<"marks="<<marks<<endl;
    }

    student operator -- ()
    {
        roll--;
        marks--;
        return *this;
    }

    student operator -- (int)
    {   
        student temp = *this;
        roll--;
        marks--;
        return temp;
    }
};
int main()
{
    student s;
    s.getdata();
    cout<<"before operator overloading"<<endl;
    s.display();
    cout<<"after operator overloading"<<endl;
    (--s).display();
    (s--).display();
    s.display();
    return 0;
}