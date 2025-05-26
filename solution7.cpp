#include <string>
#include <unordered_map>
#include <algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestPathValue2(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> in(n,0);
        vector<vector<int>> adj(n);
        //compute incoming edge
        for(auto &i : edges){
            in[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        //take out nodes with zero incoming nodes 
        queue<int> q;
        for(int i = 0; i<n ;i++){
            if(in[i]==0)
                q.push(i);
        }

        // count of each color 
        vector<int> cnt(26,0);
        vector<bool> vis (n,0);
        int maxi=0;
        function<void(int)> dfs;
        dfs = [&](int root){
                if(maxi==-1)
                    return;
                
                if(vis[root]){
                    maxi=-1;
                    return;
                }
                vis[root]=1;
                cnt[colors[root]-'a']++;

                if(adj[root].size()==0){
                    maxi = max(maxi , *max_element(cnt.begin(),cnt.end()));
                }else{
                    for(int i : adj[root])
                        dfs(i);
                }
                cnt[colors[root]-'a']--;
                vis[root]=0;
        };

        while(!q.empty() && maxi != -1){
            dfs(q.front());
            q.pop();
        }
        return maxi==0?-1:maxi;

    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> in(n,0);
        vector<vector<int>> adj(n);
        //compute incoming edge
        for(auto &i : edges){
            in[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        
        vector<int> srt;

        //take out nodes with zero incoming nodes 
        queue<int> q;

        for(int i = 0; i<n ;i++){
            if(in[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int t = q.front();q.pop();
            srt.push_back(t);
            for(int i : adj[t]){
                if(--in[i]==0){
                    q.push(i);          
                }
            }
        }

        if(srt.size()<n)
            return -1;

        vector<int> dp [26];
        int ans =0;
        for(int i = n-1 ; i>=0 ; i++){
            for(int j =0 ; j<26 ; j++){
                int maxi = 0;
                for(auto k :adj[srt[i]]){
                    maxi=max(maxi,dp[k][j]);
                }
                dp[srt[i]][j]=maxi;
            }
            dp[srt[i]][colors[srt[i]]-'a']++;
            ans=max(ans,dp[srt[i]][colors[srt[i]]-'a']);
        }
        return ans;

    }
};