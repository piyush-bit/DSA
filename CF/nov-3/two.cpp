#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        int n = maxOperations;
        while(n>=0){
            int max = pq.top();
            cout<<max<<endl;
            pq.pop();
            int i = 1 ;
            int top;
            while(n-i>=0&&max/i+1 > top){
                i++;
            }
            n=n-i;
            while(i>0){
                int q = ceil(max/i);
                cout<<q<<endl;
            
                pq.push(q);
                max=max-q;
                i--;
            }
        }

        return pq.top();
        
    }
};