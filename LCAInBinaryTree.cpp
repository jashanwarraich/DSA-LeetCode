// Q120 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Time: O(n)
// Space: O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||p==root||q==root)
            return root;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l==NULL)
            return r;
        else if(r==NULL)
            return l;
        else
            return root;
    }
};