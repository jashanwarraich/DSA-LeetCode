// Q108 https://leetcode.com/problems/binary-tree-preorder-traversal/

// RECURSIVE AND STACK SOLUTIONS TAKE O(N) TIME, AND O(N) SPACE

// Time: O(n)
// Space: O(1)
class Solution {
public:
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right&&prev->right!=cur)
                    prev=prev->right;
                if(prev->right==NULL){
                    prev->right=cur;
                    ans.push_back(cur->val);
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};