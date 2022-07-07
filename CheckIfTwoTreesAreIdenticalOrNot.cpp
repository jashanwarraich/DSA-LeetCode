// Q121 https://leetcode.com/problems/same-tree/submissions/

Time: O(n)
Space: O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        else if(q==NULL||p==NULL) return false; // above and this line can be replaced by- if(p==NULL||q==NULL) return p==q;
        return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};


//Same as above
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL||q==NULL) return p==q; //I any one is NULL, other should also be NULL, else return false
        return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};