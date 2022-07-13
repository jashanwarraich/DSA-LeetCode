// Q164 https://www.codingninjas.com/codestudio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// Time: O(N+E)+O(N+E)+O(N+E)= Topo sort + Transpose + DFS on topo
// Space: O(N+E) + O(N) + O(N)= new transpose graph + Visited + topo Stack
#include<bits/stdc++.h>
void dfs(int node, vector<bool> &vis,stack<int> &s,vector<int> adj[]){
    vis[node]=true;
    for(auto it: adj[node]){
        if(!vis[it])
            dfs(it,vis,s,adj);
    }
    s.push(node);
}

void revdfs(int node, vector<int> &cmp, vector<bool>& vis, vector<int> transpose[]){
//     cout<<node;
    cmp.push_back(node);
    vis[node]=true;
    for(auto it:  transpose[node]){
        if(!vis[it])
            revdfs(it,cmp,vis, transpose);
    }
}

vector<vector<int>> stronglyConnectedComponents(int v, vector<vector<int>> &edge){
    vector<int> adj[v];
    vector<bool> vis(v,false);
    stack<int> s;
    for(int i=0;i<edge.size();i++){
        adj[edge[i][0]].push_back(edge[i][1]);
    }
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,s,adj);
        }
    }
    vector<int> transpose[v];
    for(int i=0;i<v;i++){
        vis[i]=false;
//         transpose[edge[i][1]].push_back(edge[i][0]);
        for(auto it: adj[i])
            transpose[it].push_back(i);
    }
    vector<vector<int>> ans;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!vis[node]){
            vector<int> cmp;
            revdfs(node, cmp, vis, transpose);
//             cout<<endl;
            ans.push_back(cmp);
        }
    }
    return ans;
}