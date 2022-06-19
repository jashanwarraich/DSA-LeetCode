// https://leetcode.com/problems/unique-paths/

//O(m) if int r= m-1;
// O(n) if int r=n-2;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N= m+n-2;
        int r= m-1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }
        return (int)res;
    }
};

//Memorisation O(n*m)
class Solution {
public:
    int cp(int m, int n,int i, int j,vector<vector<int>>&dp){
        if(i==m-1&&j==n-1) return 1;
        if(i>=m||j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else return cp(m,n,i+1,j,dp) + cp(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        int i=0,j=0;
        vector<vector<int>>dp(m, vector<int> (n));
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++)
                dp[a][b]=-1;
        }
        return cp(m,n,i,j,dp);
    }
};


// Exponential complexity (RECURSION)
class Solution {
public:
    int cp(int m, int n,int i, int j){
        if(i==m-1&&j==n-1) return 1;
        if(i>=m||j>=n) return 0;
        else return cp(m,n,i+1,j) + cp(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        int i=0,j=0;
        return cp(m,n,i,j);
    }
};

