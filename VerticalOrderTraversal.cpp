// Q113 https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Time: O(nlog(N))    //log(n) for multiset
// Space: O(N)   
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) todo.push({node->left,{x-1,y+1}});
            if(node->right) todo.push({node->right,{x+1,y+1}});
        }
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end()); //PARAMETERS explained below
// vector_name.insert(position, iterator1, iterator2)
// position – It specifies the position at which insertion is to be done in vector.
// iterator1 – It specifies the starting position from which the elements are to be inserted
// iterator2 – It specifies the ending position till which elements are to be inserted
            }
            ans.push_back(col);
        }
        return ans;
    }
};