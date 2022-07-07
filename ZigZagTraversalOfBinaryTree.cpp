// Q122 https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> v(s);
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                int ind=(lefttoright)?i:s-i-1;
                v[ind]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lefttoright=!lefttoright;
            ans.push_back(v);
        }
        return ans;
    }
};