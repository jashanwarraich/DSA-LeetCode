// Q105 https://leetcode.com/problems/binary-tree-preorder-traversal/

// Iterative
class Solution {
public:
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        TreeNode* node=root;
        s.push(node);
        while(!s.empty()){
            node=s.top();
            ans.push_back(node->val);
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }
};


//Recursive
class Solution {
public:
     vector<int> ans;
     vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};