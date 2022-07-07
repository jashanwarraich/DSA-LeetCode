// Q118 https://leetcode.com/problems/diameter-of-binary-tree/

// Time: O(n)
class Solution {
public:
    int h(TreeNode* root,int &ans) {    //height function modified to manage diameter and height in the same
        if(!root) return 0;
        int lh=h(root->left, ans);
        int rh=h(root->right, ans);
        ans=max(ans,lh+rh);
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        h(root,ans);
        return ans;
    }
};


// Time: O(n*n)
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