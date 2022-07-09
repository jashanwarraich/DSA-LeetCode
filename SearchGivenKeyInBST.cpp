// Q132 https://leetcode.com/problems/search-in-a-binary-search-tree/


// Time: O(logn)
// Space: O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int x) {
        while(root!=NULL&&root->val!=x){
            root=root->val>x?root->left:root->right;
        }
        return root;
    }
};


// Time: O(logn)
// Space: O(n)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int x) {
        if(!root) return NULL;
        if(root->val==x) return root;
        if(root->val>x) return searchBST(root->left,x);
        else return searchBST(root->right,x);
    }
};