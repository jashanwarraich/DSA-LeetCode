// Q129

//Covert the tree into its mirror
// https://practice.geeksforgeeks.org/problems/mirror-tree/1
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node==NULL) return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left,node->right);
    }
};

// Invert the binary tree
// https://www.codingninjas.com/codestudio/problems/invert-a-binary-tree_1281382?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
bool helper(TreeNode<int> *root,TreeNode<int> *leaf,stack<TreeNode<int> *> &st){
    st.push(root);
    if(root->left==NULL&&root->right==NULL){ //root is leaf node
        if(root->data==leaf->data) return true; //root is same value as leaf
        else {st.pop(); return false;}
    }
    if(root->left && helper(root->left,leaf,st)) return true;
    if(root->right && helper(root->right,leaf,st)) return true;
    
    st.pop();
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(!root) return NULL;
    stack<TreeNode<int> *> st;
    helper(root,leaf,st);
    TreeNode<int> *newr=st.top();
    st.pop();
    TreeNode<int> *par=newr; //parent
    while(!st.empty()){
        auto cur=st.top();
        st.pop();
        if(cur->left==par){
            cur->left=NULL;
            par->left=cur;
        }
        else{
            cur->right=cur->left;
            cur->left=NULL;
            par->left=cur;
        }
        par=cur;
    }
    return newr;
}
