// Q140 https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Time: O(n)
// Space: O(1) 

class Solution {
public:
    void helper(TreeNode* root, int &k, int &ans){
        if(!root) return;
        helper(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->val;
            return;
        }
        helper(root->right,k,ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        helper(root,k,ans);
        return ans;
    }
};