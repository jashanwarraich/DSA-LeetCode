// Q153 https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(E+V)  //DFS
// Space: O(E+V)+O(V)+O(V)   


void dfsfunc(int node, vector<int> adj[],vector<int> &cmp, vector<int> &vis){
    vis[node]=1;
    cmp.push_back(node);
    for(auto it: adj[node]){
        if(vis[it]==0){
            dfsfunc(it,adj,cmp,vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edge){
    vector<vector<int>> dfs;
    vector<int> vis(v,0);
    vector<int> adj[v]; //vector of arrays
    for(int i=0;i<e;i++){
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    for(int i=0;i<v;i++){
        if(vis[i]==0){
            vector<int> cmp; //component
            dfsfunc(i,adj,cmp,vis);
            dfs.push_back(cmp);
        }
    }
    return dfs;
}