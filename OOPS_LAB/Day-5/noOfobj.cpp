//3.wap  to count no of obj used in a program using static variable . create a static member function to check the total number of object created in the program at the end 

#include <iostream>
using namespace std;
class student{
    
        static int count  ;
        public:
        student(){
            count++;
        }
        
        static int noOfObj(){
            return count ;
        }
};

int student::count = 0;

int main(){
    student s1,s2,s3;
    cout<<student::noOfObj()<<endl;
    return 0;
}