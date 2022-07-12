// Q157 https://leetcode.com/problems/course-schedule/

// Time: O(E+V)  //DFS
// Space: O(E+V)+O(V)+O(V)   


class Solution {
    bool dfscycle(int s,vector<bool> &vis,vector<bool> &dfsvis,vector<int> adj[]){
        vis[s]=true;
        dfsvis[s]=true;
        for(auto it: adj[s]){
            if(!vis[it]){
                if(dfscycle(it,vis,dfsvis,adj)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        dfsvis[s]=false;
        return false;
    }
public:
    bool canFinish(int v, vector<vector<int>>& edge) {
        vector<bool> vis(v,false);
        vector<bool> dfsvis(v,false);
        vector<int> adj[v]; //vector of arrays
        for(int i=0;i<edge.size();i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            // adj[edge[i][1]].push_back(edge[i][0]);  because directed graph
        }
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfscycle(i,vis,dfsvis,adj)) return false;
            }
        }
        return true;
    }
};