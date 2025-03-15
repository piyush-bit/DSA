#include <iostream>
using namespace std ;
class Quardatic {
    public : 
        void solveQuardatic (){
            double a , b , c ; 
            cout << "Enter co-efficients of quardatic in format  " <<endl;
            cout << "in format ax2 + bx + c" <<endl;
            cin >> a;
            cin >> b ;
            cin >> c ;

            double d = (b*b-4*a*c);
            if(d<0){
                double complexpart = pow(-d,0.5)/(2*a);
                double realpart = -b/(2*a);
                cout << "roots are imaginary"<<endl;
                
                cout << realpart <<connector(-complexpart) << -complexpart <<"j"<<endl;
                cout << realpart <<connector(complexpart) << complexpart <<"j"<<endl;
                cout << realpart <<((complexpart>=0) ? "+":"") << complexpart <<"j"<<endl;

            }else {

            double ans1 = (-b+pow((b*b-4*a*c),0.5))/(2*a);
            double ans2 = (-b-pow((b*b-4*a*c),0.5))/(2*a);

            cout << "answers are " << ans1 << " and " << ans2  <<endl;

            }
        }

        static string connector ( double complexpart){
            return (complexpart>=0) ? "+":"";
        }

};

int main () {
    Quardatic q;
    q.solveQuardatic();
    return 0 ;

}