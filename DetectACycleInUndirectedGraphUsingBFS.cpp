// Q155 https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// Time: O(E+V)  //BFS
// Space: O(E+V)+O(V)+O(V)   


#include<bits/stdc++.h>

    bool bfscycle(int s,vector<bool> &vis,vector<int> adj[]){
        queue<pair<int,int>> q;
        vis[s]=true;
        q.push({s,-1});
        sort(adj[s].begin(),adj[s].end());
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push({it,node});
                }
                else{
                    if(par!=it) return true;
                }
            }
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
                if(bfscycle(i,vis,adj)) return "Yes";
            }
        }
        return "No";
        
    }