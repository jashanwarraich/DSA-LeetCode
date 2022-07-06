// Q118 https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return 1+max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int op1=maxDepth(root->left)+maxDepth(root->right);
        int op2=diameterOfBinaryTree(root->left);
        int op3=diameterOfBinaryTree(root->right);
        return max(op1,max(op2,op3));
    }
};