// Q144 https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/

// Returm sum
// Time: O(n)  
// Space: O(1) 
class nodeValue{
public:
    int maxNode, minNode,maxSum;

    nodeValue(int minNode,int maxNode,int maxSum){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSum=maxSum;
    }
};
class Solution {
private:
    int ans=INT_MIN;
    nodeValue helper(TreeNode* root){
        if(root==NULL) return nodeValue(INT_MAX,INT_MIN,0);
        auto l=helper(root->left);
        auto r=helper(root->right);
        if(root->val>l.maxNode&&root->val<r.minNode){
            ans=max(ans,l.maxSum+r.maxSum+root->val);
            return nodeValue(min(l.minNode,root->val),max(r.maxNode,root->val),l.maxSum+r.maxSum+root->val);
        }
        return nodeValue(INT_MIN,INT_MAX,max(l.maxSum,r.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root).maxSum;
        return ans<0?0:ans;
        // return helper(root).maxSum;
    }
};









// Q144 https://www.codingninjas.com/codestudio/problems/893103?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// Returm size
// Time: O(n)  
// Space: O(1) 


class nodeValue{
public:
    int maxNode, minNode,maxSum;

    nodeValue(int minNode,int maxNode,int maxSum){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSum=maxSum;
    }
};

nodeValue helper(TreeNode<int>* root){
    if(root==NULL) return nodeValue(INT_MAX,INT_MIN,0);
    auto l=helper(root->left);
    auto r=helper(root->right);
    if(root->data>l.maxNode&&root->data<r.minNode){
        return nodeValue(min(l.minNode,root->data),max(r.maxNode,root->data),l.maxSum+r.maxSum+1);
    }
    return nodeValue(INT_MIN,INT_MAX,max(l.maxSum,r.maxSum));
}


int largestBST(TreeNode<int>* root){
    // int ans= helper(root).maxSum;
    // return ans<0?0:ans;
    return helper(root).maxSum;
}


