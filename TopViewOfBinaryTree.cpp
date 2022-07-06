// Q111 https://www.codingninjas.com/codestudio/problems/799401?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(n)
// Space: O(n)

#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mpp;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        TreeNode<int> *node=q.front().first;
        int line=q.front().second;
        q.pop();
        if(mpp.find(line)==mpp.end()) mpp[line]=node->val;   //only change this line of the BOTTOM view to get TOP View  (remove the if condition)
        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }
    for(auto it:mpp)
        ans.push_back(it.second);
    return ans;
}