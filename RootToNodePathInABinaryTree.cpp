// Q114 https://www.interviewbit.com/problems/path-to-given-node/

// Time: O(N) 
// Space: O(H)  


 bool getpath(TreeNode* root, vector<int> & ans, int x){
     if(!root) return false;
     ans.push_back(root->val);
     if(root->val==x) return true;
     if(getpath(root->left,ans,x)||getpath(root->right,ans,x))
        return true;
    ans.pop_back();
    return false;
 }
 
vector<int> Solution::solve(TreeNode* root, int x) {
    vector<int> ans;
    if(!root) return ans;
    getpath(root,ans,x);
    return ans;
}
