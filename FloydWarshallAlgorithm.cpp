// Q167 https://www.codingninjas.com/codestudio/problems/2041979?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Time: O(n*n*n)
// Space: O(n*n)


int floydWarshall(int v, int e, int src, int dest, vector<vector<int>> &edge) {
    vector<vector<int>> g(v+1,vector<int>(v+1,1e9));
    for(auto it:edge){
        g[it[0]][it[1]]=it[2];
    }
    int num=v+1;
    while(num--) g[num][num]=0;
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(g[i][k]!=1e9&&g[k][j]!=1e9)
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    return g[src][dest];
}