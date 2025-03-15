// Wap to overload area function to find the area of triangle , rectangle , square and circle , make a menu driven program 

#include <iostream>
using namespace std;

class Shape
{
public: 
    //rectangle  
    int area(int x, int y)
    {
        return (x * y);
    }

    //square
    int area(int x)
    {
        return (x * x);
    }

    //circle 
    double area(float x)
    {
        return (3.14 * x * x);
    }

    //triangle
    double area (double a , double b , double c ){
        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};

int main(){
    
    Shape obj;
    while(true){
        int choice;
        cout << "1. Rectangle" << endl;
        cout << "2. Square" << endl;
        cout << "3. Circle" << endl;
        cout << "4. Triangle" << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch (choice) {
            
        case 1:{
            int a , b ; 
            cout << "Enter length and breadth : "<< endl;
            cin >> a >> b;
            cout << "Area of rectangle : " << obj.area(a,b) << endl;
            break;}
        case 2:
            {
            int a ; 
            cout << "Enter side : " << endl;
            cin >> a;
            cout << "Area of square : " << obj.area(a) << endl;
            break;
            }
        case 3:
            {
            float r;
            cout << "Enter radius : " << endl;
            cin >> r;
            cout << "Area of circle : " << obj.area(r) << endl;
            break;
            }
        case 4:
            {
            int a , b , c ; 
            cout << "Enter three sides : " << endl;
            cin >> a >> b >> c;
            cout << "Area of triangle : " << obj.area(a, b, c) << endl;
            break;}
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "Do you want to continue (1/0) : " << endl;
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
    }
    return 0;
}