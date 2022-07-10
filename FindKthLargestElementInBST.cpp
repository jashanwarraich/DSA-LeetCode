// Q141 https://www.codingninjas.com/codestudio/problems/920438?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// Time: O(n)
// Space: O(1) 


void helper(TreeNode<int> * root,int &k,int &ans){
    if(!root) return;
    helper(root->right,k,ans);
    k--;
    if(k==0){
        ans=root->data;
        return;
    }
    helper(root->left,k,ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) {
    int ans=-1;
    helper(root,k,ans);
    return ans;
}