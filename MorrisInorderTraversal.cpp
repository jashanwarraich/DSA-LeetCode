// Q107 https://leetcode.com/problems/binary-tree-inorder-traversal/

// RECURSIVE AND STACK SOLUTIONS TAKE O(N) TIME, AND O(N) SPACE

// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};