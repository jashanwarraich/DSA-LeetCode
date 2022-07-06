// Q112 https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(3*n)    {taversing each node thrice}
// Space: O(4*n)   {pre+post+in+stack}

#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    if(!root) return ans;
    vector<int> pre,in,post;
    stack<pair<BinaryTreeNode<int>*,int>> s;
    s.push({root,1});
    while(!s.empty()){
        auto it=s.top();
        s.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left) s.push({it.first->left,1});
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right) s.push({it.first->right,1});
        }
        else{
            post.push_back(it.first->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
}