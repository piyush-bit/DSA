/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return f(preorder,postorder,0,n,0,n);
    }
    TreeNode* f(vector<int>& preorder, vector<int>& postorder,int pr1,int pr2 , int po1,int po2){
        if(preorder[pr1]!=postorder[po2-1]){
            cout<<"Error \n";
            return nullptr;
        }

        TreeNode* t = new TreeNode(preorder[pr1]);

        if(pr2-pr1 ==1)
        return t;
        // do checks 


        int leftT = preorder[pr1+1];
        int leftTS = po1;
        while(postorder[leftTS<po2 && leftTS]!=leftT){
            leftTS++;
        }

        t->left = f(preorder,postorder,pr1+1,pr1+1+leftTS-po1+1,po1,leftTS+1);
        t->right = f(preorder,postorder,pr1+1+leftTS-po1+1,pr2,leftTS+1,po2-1);

        return t;
    }

};
