// Q117 https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Time: O(H) OR O(logn) 
// Space: O(N)  

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return 1+max(l,r);
    }
};