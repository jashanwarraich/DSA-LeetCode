// Q145 https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Time: O(n)  
// Space: O(n) 



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur=q.front();
            q.pop();
            if(cur==NULL) s.append("#,");
            else{
                s.append(to_string(cur->val)+",");
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")cur->left=NULL;
            else{
                TreeNode*l=new TreeNode(stoi(str));
                cur->left=l;
                q.push(l);
            }
            getline(s,str,',');
            if(str=="#")cur->right=NULL;
            else{
                TreeNode*r=new TreeNode(stoi(str));
                cur->right=r;
                q.push(r);
            }
        }
        return root;
    }
};




//traversals line inorder+preorder can also be used