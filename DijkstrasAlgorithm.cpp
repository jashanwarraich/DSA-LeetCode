// Q165 https://www.codingninjas.com/codestudio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O((N+E)*LoG(N))
// Space: O(N+E) + O(N) + O(N)

#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &edge, int v, int e, int src) {
    vector<pair<int,int>> adj[v];
    for(int i=0;i<e;i++){
        adj[edge[i][0]].push_back(make_pair(edge[i][1],edge[i][2]));
        adj[edge[i][1]].push_back(make_pair(edge[i][0],edge[i][2]));
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    q.push(make_pair(0,src));
    while(!q.empty()){
        int dis=q.top().first;
        int prev=q.top().second;
        q.pop();
//         vector<pair<int,int>> :: iterator it;
        for(auto it:adj[prev]){
            int next=it.first;
            int nextdist=it.second;
            if(dist[next]>dis+nextdist){
                dist[next]=dis+nextdist;
                q.push(make_pair(dist[next],next));
            }
        }
        

    }
    return dist;
}