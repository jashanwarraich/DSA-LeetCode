// Q152 https://leetcode.com/problems/flood-fill/submissions/

// Time: O(E+V)  //DFS
// Space: O(V)   //for visited


class Solution {
    void dfs(Node* node, Node* copy, vector<Node*> &vis){
        vis[copy->val]=copy;
        for(auto i:node->neighbors){
            if(vis[i->val]==NULL){
                Node* nn=new Node(i->val);
                copy->neighbors.push_back(nn);
                dfs(i,nn,vis);
            }
            else{
                copy->neighbors.push_back(vis[i->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vector<Node*> vis(1000,NULL);
        Node* copy= new Node(node->val);
        dfs(node,copy,vis);
        return copy;
    }
};