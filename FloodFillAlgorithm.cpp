// Q151 https://leetcode.com/problems/flood-fill/submissions/

class Solution {
public:
    void helper(vector<vector<int>>& a, int i, int j,int nc, int oc, int m, int n){
        if(i>=m||i<0||j>=n||j<0||a[i][j]!=oc) return;
        a[i][j]=nc;
        helper(a,i-1,j,nc,oc,m,n);
        helper(a,i,j+1,nc,oc,m,n);
        helper(a,i+1,j,nc,oc,m,n);
        helper(a,i,j-1,nc,oc,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int nc) {
        int oc=a[sr][sc];
        if(oc==nc) return a;
        helper(a,sr,sc,nc,oc,a.size(),a[0].size());
        return a;
    }
};