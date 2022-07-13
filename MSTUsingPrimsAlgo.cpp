// Q168 https://www.codingninjas.com/codestudio/problems/1095633?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(n+e) + O(nlogn)
// Space: O(n*n)

#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<g.size(); ++i) {
        adj[g[i].first.first].push_back({g[i].first.second, g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first, g[i].second});
    }
    
    vector<int> parent(n+1, -1);
    vector<int> dist(n+1, INT_MAX);
    vector<bool> mstDone(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dist[1] = 0;
    parent[1] = -1;
    
    while(!q.empty()) {
        int node = q.top().second;
        int nodeDist = q.top().first;
        mstDone[node] = true;
        q.pop();
        
        for(auto &it : adj[node]) {
            int n = it.first;
            int d = it.second;
            
            if(!mstDone[n] && dist[n] > d) {
                parent[n] = node;
                dist[n] = d;
                q.push({dist[n], n});
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; ++i) ans.push_back({{parent[i], i}, dist[i]});
    
    return ans;
}



  while(!q.empty()) {
        int node = q.top().second;
        int nodeDist = q.top().first;
        mstset[node] = true;
        q.pop();
        
        for(auto &it : adj[node]) {
            int n = it.first;
            int d = it.second;
            
            if(!mstset[n] && key[n] > d) {
                parent[n] = node;
                key[n] = d;
                q.push({key[n], n});
            }
        }
    }



        for(auto &it : adj[u]) {
            int n = it.first;
            int d = it.second;
            
            if(!mstset[n] && key[n] > d) {
                parent[n] = u;
                key[n] = d;
                q.push({key[n], n});
            }
        }
    }















#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int v, int e, vector<pair<pair<int, int>, int>> &edge){
    vector<pair<int,int>> adj[v+1]; //vector of arrays
    for(int i=0;i<e;i++){
        adj[edge[i].first.first].push_back({edge[i].first.second,edge[i].second});
        adj[edge[i].first.second].push_back({edge[i].first.first,edge[i].second});
    }
    int parent[v+1];
    int key[v+1];
    bool mstset[v+1];
    for(int i=1;i<=v;i++){
        key[i]=INT_MAX, mstset[i]=false;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    key[1]=0;
    parent[1]=-1;
    q.push({0,1});
    for(int cnt=0;cnt<v-1;cnt++){
        int u=q.top().second;
        q.pop();
        mstset[u]=true;
        for(auto it: adj[u]){
            int v=it.first;
            int weight=it.second;
            if(mstset[v]==false&&weight<key[v]){
                parent[v]=u;
                q.push({key[v],v});
                key[v]=weight;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=v;i++) ans.push_back({{parent[i],i},key[i]});
    return ans;
    
}
