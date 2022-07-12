// Q160 https://www.codingninjas.com/codestudio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// Time: O(E+V)  //DFS
// Space: O(E+V)+O(V)+O(V)  


#include<bits/stdc++.h>
void dfs(int node, vector<bool> &vis,stack<int> &s,vector<int> adj[]){
    vis[node]=true;
    for(auto it: adj[node]){
        if(!vis[it])
            dfs(it,vis,s,adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edge, int v, int e)  {
    vector<int> adj[v];
    vector<bool> vis(v,false);
    stack<int> s;
    for(int i=0;i<e;i++){
        adj[edge[i][0]].push_back(edge[i][1]);
    }
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,s,adj);
        }
    }
    vector<int> topo;
    while(!s.empty()){
        topo.push_back(s.top());
        s.pop();
    }
    return topo;
}