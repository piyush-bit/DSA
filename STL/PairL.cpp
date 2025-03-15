#include<iostream>

using namespace std;
void main (){
    // pair<int,int> p;
    pair<int,int> p = {10,20};

    //pair<int , pair<int,int>> p;
    // pair<int , pair<int,int>> p = {10,{20,30}};

    cout<<p.first<<" "<<p.second<<endl;

}