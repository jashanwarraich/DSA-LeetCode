// Q126 https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Time: O(n)
// Space: O(n)

class Solution {
public:
    
    TreeNode* helper(vector<int> &post,int ps,int pe,
                  vector<int> &in,int is,int ie,
                   map<int,int> &m){
        if(ps>pe||is>ie) return NULL;
        TreeNode* root=new TreeNode(post[pe]);
        int inroot=m[root->val];
        int numsleft=inroot-is;
        root->left=helper(post,ps,ps+numsleft-1,in,is,inroot-1,m);
        root->right=helper(post,ps+numsleft,pe-1,in,inroot+1,ie,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int psize=postorder.size(), isize=inorder.size();
        // if(psize==0||isize==0) return NULL;
        map<int,int> m;
        for(int i=0;i<isize;i++)
            m[inorder[i]]=i;
        TreeNode* root=helper(postorder,0,psize-1,inorder,0,isize-1,m);
        return root;
    }
};




// https://classroom.codingninjas.com/app/classroom/me/6855/content/92019/offering/1027889/problem/355
//Given array (not vectors) and not using hashmap
BinaryTreeNode<int>* buildTree(int *postOrder, int postLength, int *inOrder, int inLength) {
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postOrder[postLength-1]);
    
    if(postLength == 1)    // base case when only root is present and no left or right node
        return root;
    
    if(postLength == 0)    //if one of both right or left is present check for 2, 1 2, 1 2;;;dry run it
        return NULL;
    
    int i = 0;
    while(inOrder[i] != postOrder[postLength - 1]){
        i++;
    }
    
    int left_size = i;
    int right_size = inLength -i - 1;
    
    BinaryTreeNode<int> *leftSubtree = buildTree(postOrder, left_size, inOrder, left_size);
    BinaryTreeNode<int> *rightSubtree = buildTree(postOrder + left_size, right_size, inOrder + 1 + left_size, right_size);
    
    root -> left = leftSubtree;
    root -> right = rightSubtree;
    
    return root;
}