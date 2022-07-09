// Q137 https://www.codingninjas.com/codestudio/problems/893049?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(n)
// Space: O(1)  

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key){
    pair<int,int> p;
    p.first=-1;
    p.second=-1;
    BinaryTreeNode<int>* nr=root;
    while(root!=NULL){
        if(root->data<=key) root=root->right;
        else{
            p.second=root->data;
            root=root->left;
        }
    }
    root=nr;
    while(root!=NULL){
        if(root->data>=key) root=root->left;
        else{
            p.first=root->data;
            root=root->right;
        }
    }
    return p;
}
