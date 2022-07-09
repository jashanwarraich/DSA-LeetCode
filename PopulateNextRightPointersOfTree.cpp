// Q131 https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Time: O(n)
// Space: O(n)



class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        int pos=0; //node index at this level
        int till=1; //nodes at current level
        while(!q.empty()){
            Node* cur= q.front();
            if(cur->left) {
                q.push(cur->left); 
                q.push(cur->right);
            } //complete , if one child exist right will also exist
            q.pop();
            pos++;
            if(pos==till){
                cur->next=NULL;
                till*=2;
                pos=0;
            }
            else{
                cur->next=q.front();
            }           
        }
        return root;
    }
};