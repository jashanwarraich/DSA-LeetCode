// Q121 https://leetcode.com/problems/same-tree/submissions/

Time: O(n)
Space: O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        else if(q==NULL||p==NULL) return false;
        return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};