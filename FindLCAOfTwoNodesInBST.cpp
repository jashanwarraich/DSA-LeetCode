// Q136 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Time: O(n)
// Space: O(1)  ignoring recursion calling stack space  

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        if(root->val<p->val&&root->val<q->val)
            return lowestCommonAncestor(root->right,p,q);
        else if(root->val>p->val&&root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};