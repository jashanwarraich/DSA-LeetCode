// Q119 https://leetcode.com/problems/balanced-binary-tree/submissions/

// Time: O(n)
class Solution {
public:
    int dfsheight(TreeNode *root) {
        if(!root) return 0;
        
        int lh=dfsheight(root->left);
        if(lh==-1) return -1;
        
        int rh=dfsheight(root->right);
        if(rh==-1) return -1;
        
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }   

    bool isBalanced(TreeNode* root) {
        return dfsheight(root)!=-1;
    }
};


//Alternative of above code (Same approach and time complexity)
class Solution {
public:
    int dfsheight(TreeNode *root) {
        if(!root) return 0;
        int lh=dfsheight(root->left);
        int rh=dfsheight(root->right);
        if(abs(lh-rh)>1) return -1;
        if(lh==-1||rh==-1) return -1;
        return max(lh,rh)+1;
    }   

    bool isBalanced(TreeNode* root) {
        return dfsheight(root)!=-1;
    }
};


// Time: O(n*n)
class Solution {
public:
    int height(TreeNode *root) {
        if(root==NULL)
            return 0;
        return 1+ max(height(root->left),height(root->right));
    }   

    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        if((abs(lh-rh)>1)){
            return false;
        }
        else{ 
            if(!isBalanced(root->left)||!isBalanced(root->right))
                return false;
        }
        return true;
    }
};