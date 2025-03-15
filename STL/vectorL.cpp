#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> v2;
    v2.push_back({1, 2});
    v2.emplace_back(3, 4);

    for (auto i : v)
        cout << i << endl;

    // different initializations

    // vector<int> v3(10, 1);
    // vector<int> v4(10);
    // v4.resize(10, 1);
    // vector<int> v5(v3);

    //iterators
    auto it = v.begin();
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    it = v.end();
    --it;
    cout << *it << endl;

    //reverse iterators
    auto rit = v.rbegin();
    cout << *rit << endl;
    ++rit;
    cout << *rit << endl;
    rit = v.rend();
    --rit;
    cout << *rit << endl;



    //capacity
    cout << v.capacity() << endl;
    v.reserve(10);
    cout << v.capacity() << endl;
    v.shrink_to_fit();
    cout << v.capacity() << endl;

    //size
    cout << v.size() << endl;
    v.resize(10);
    cout << v.size() << endl;
    v.clear();
    cout << v.size() << endl;

    //empty
    cout << v.empty() << endl;
    v.push_back(1);
    cout << v.empty() << endl;

    //clear
    v.clear();
    cout << v.empty() << endl;

    //at
    cout << v.at(0) << endl;
    cout << v.at(1) << endl;

    // sort an array 
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sort(a, a + 10 , [](int a, int b){return a > b;});
    for (int i = 0; i < 10; i++)
        cout << a[i] << endl;




}