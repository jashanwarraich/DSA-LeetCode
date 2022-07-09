// Q134 https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Time: O(n)
// Space: O(n)

class Solution {
public:
    TreeNode* helper(vector<int> pre,int &i, int bound){
        if(i>=pre.size()||pre[i]>bound) return NULL; //remember to pass i as reference
        TreeNode* nr=new TreeNode(pre[i++]);
        nr->left=helper(pre,i,nr->val);
        nr->right=helper(pre,i,bound);
        return nr;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,i, INT_MAX);
    }
};