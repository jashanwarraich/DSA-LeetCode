// Q124 https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Time: O(n)
// Space: O(n)

class Solution {
    int helper(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int l=max(0,helper(root->left,maxi));
        int r=max(0,helper(root->right,maxi));
        maxi=max(maxi,l+r+root->val);
        return max(l,r)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};