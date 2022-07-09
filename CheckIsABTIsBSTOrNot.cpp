// Q135 https://leetcode.com/problems/validate-binary-search-tree/

// Time: O(n)
// Space: O(1)  ignoring recursion calling stack space

class Solution {
public:
    bool helper(TreeNode* root,long mi, long ma){
        if(!root) return true;
        if(root->val>=ma||root->val<=mi) return false;
        return helper(root->left,mi,root->val) && helper(root->right,root->val,ma);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, (long)INT_MIN-1,(long)INT_MAX+1);
    }
};
