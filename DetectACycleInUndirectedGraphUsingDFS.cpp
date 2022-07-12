// Q156 https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(E+V)  //DFS
// Space: O(E+V)+O(V)+O(V)   


bool dfscycle(int node, int par, vector<bool> &vis, vector<int> adj[]){
    vis[node]=true;
    for(auto it: adj[node]){
        if(vis[it]==0){
            if(dfscycle(it,node,vis,adj)) return true;
        }
        else if(it!=par) return true;
    }
    return false;
}



string cycleDetection (vector<vector<int>>& edge, int v, int e){ 
    vector<bool> vis(v+1,false);
    vector<int> adj[v+1]; //vector of arrays
    for(int i=0;i<e;i++){
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            if(dfscycle(i,-1,vis,adj)) return "Yes";
        }
    }
    return "No";
}