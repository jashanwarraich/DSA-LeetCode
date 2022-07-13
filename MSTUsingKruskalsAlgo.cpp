// Q169 https://www.codingninjas.com/codestudio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(ElogE)+ O(M*4alpha)=O(ElogE)
// Space: set+ parent +rank =O(E)+O(N)+O(N)+O(N)


#include<bits/stdc++.h>
bool sortcol3(const vector<int> &v1,const vector<int> &v2){
    return v1[2]<v2[2];
}

int findpar(int u, vector<int> &par){
    if(u==par[u]) return u;
    return par[u]=findpar(par[u],par);
}

void makeunion(int u, int v, vector<int> &par, vector<int> &rank){
    u=findpar(u,par);
    v=findpar(v,par);
    if(rank[u]<rank[v]) par[u]=v;
    else if(rank[u]>rank[v]) par[v]=u;
    else{
        par[v]=u;
        rank[u]++;
    }
}


int kruskalMST(int v, int e, vector<vector<int>> &edge) {
	sort(edge.begin(),edge.end(),sortcol3);
    vector<int> par(v+1);
    for(int i=1;i<v+1;i++) par[i]=i;
    vector<int> rank(v+1,0);
    int cost=0;
//     vector<pair<int,int>> kedges; //edges present in MST, can be used to return MST edges
    for(auto i: edge){
        if(findpar(i[0],par)!=findpar(i[1],par)){
            cost+=i[2];
//             kedges.push_back({i[0],i[1]});
            makeunion(i[0],i[1],par,rank);
        }
    }
    

    return cost;
}