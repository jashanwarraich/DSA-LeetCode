// Q142 https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Time: O(n)
// Space: O(n) 

class Solution {
public:
    bool helper(TreeNode* root,int k,unordered_set <int> &m){
        if(!root) return false;
        if(m.find(k-root->val)!=m.end()) return true;
        m.insert(root->val);
        return helper(root->left,k,m)||helper(root->right,k,m); 
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set <int> m;
        return helper(root,k,m);
    }
};