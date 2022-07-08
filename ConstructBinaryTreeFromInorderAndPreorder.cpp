// Q125 https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Time: O(n)
// Space: O(n)

class Solution {
public:
    TreeNode* helper(vector<int> &pre,int ps,int pe,
                  vector<int> &in,int is,int ie,
                   map<int,int> &m){
        if(ps>pe||is>ie) return NULL;
        TreeNode* root=new TreeNode(pre[ps]);
        int inroot=m[root->val];
        int numsleft=inroot-is;
        root->left=helper(pre,ps+1,ps+numsleft,in,is,inroot-1,m);
        root->right=helper(pre,ps+numsleft+1,pe,in,inroot+1,ie,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int psize=preorder.size(), isize=inorder.size();
        // if(psize==0||isize==0) return NULL;
        map<int,int> m;
        for(int i=0;i<isize;i++)
            m[inorder[i]]=i;
        TreeNode* root=helper(preorder,0,psize-1,inorder,0,isize-1,m);
        return root;
    }
};


// https://classroom.codingninjas.com/app/classroom/me/6855/content/92019/offering/1027887/problem/100
//Given array (not vectors) and not using hashmap

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[0]);
    
    if(preLength==1){
        return root;
    }
    if(preLength==0){
        return NULL;
    }
    int i;
    for(i=0;i<inLength;i++){
        if(inorder[i]==preorder[0])
            break;
    }
    BinaryTreeNode<int>* l=buildTree(preorder+1,i,inorder, i);
    BinaryTreeNode<int>* r=buildTree(preorder+1+i,inLength-i-1,inorder+1+i, inLength-i-1);
    root->left=l;
    root->right=r;

}
