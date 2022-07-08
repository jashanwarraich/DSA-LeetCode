// Q128 https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Using Morris traversal
// Time: O(n)
// Space: O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left){
                TreeNode* prev=cur->left;
                while(prev->right) prev=prev->right;
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;           
        }
    }
};


//Recursion  (Reverese preorder)
// Time: O(n)
// Space: O(n)
class Solution {
  node * prev = NULL;
  public:
    void flatten(node * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};


//Iteratively  (Using Stack)
// Time: O(n)
// Space: O(n)
class Solution {
  node * prev = NULL;
  public:
   void flatten(node * root) {
  if (root == NULL) return;
  stack < node * > st;
  st.push(root);
  while (!st.empty()) {
    node * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }

}


};


