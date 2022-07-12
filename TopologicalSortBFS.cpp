// Q159 https://www.codingninjas.com/codestudio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// Time: O(E+V)  //BFS
// Space: O(E+V)+O(V)+O(V)  



//Kahns Algo, Omly possible for the Directed Acyclic Graph (DAG)
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edge, int v, int e)  {
    vector<int> adj[v]; //vector of arrays
    for(int i=0;i<e;i++){
        adj[edge[i][0]].push_back(edge[i][1]);
//         adj[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int> q;
    vector<int> indeg(v,0);
    for(int i=0;i<v;i++){
        for(auto it: adj[i])
            indeg[it]++;
    }
    for(int i=0;i<v;i++){
        if(indeg[i]==0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    return topo;
}