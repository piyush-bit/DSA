//5.wap to demonstrate the use of #define for creating a variable , a function 

#include <iostream>
using namespace std;
#define pi 3.14
#define area(r) pi*r*r
int main()
{   int x ;
    cout<<"Enter Radius "<<endl;
    cin>>x;
    cout<<area(x)<<endl;;
    return 0;
}
