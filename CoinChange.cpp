// Q178 https://leetcode.com/problems/coin-change/



// Recursion
// Time: O(2^n)
// Space: O(n) 
class Solution {
    int f(int i, int j,vector<vector<int>>& g){
        if(i==0&&j==0) return g[0][0];
        if(i<0||j<0) return 1e9;
        int up=g[i][j]+f(i-1,j,g);
        int left=g[i][j]+f(i,j-1,g);
        return min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        return f(n-1,m-1,g);
    }
};

// Memorisation
// Time: O(N*m)
// Space: O(N*M)+O(N) = auxiliary stack space+ dp
class Solution {
    int f(int i, int j,vector<vector<int>>& g,vector<vector<int>> &dp){
        if(i==0&&j==0) return g[0][0];
        if(i<0||j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=g[i][j]+f(i-1,j,g,dp);
        int left=g[i][j]+f(i,j-1,g,dp);
        return dp[i][j]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,g,dp);
    }
};

// DP
// Time: O(N*m)
// Space: O(N*M)
class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) dp[i][j]= g[0][0];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=g[i][j]+dp[i-1][j];
                    if(j>0) left=g[i][j]+dp[i][j-1];
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

// TABULATION
// Time: O(N*m)
// Space: O(2*M)
class Solution {

public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> p(m,0),c(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) c[j]= g[0][0];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=g[i][j]+p[j];
                    if(j>0) left=g[i][j]+c[j-1];
                    c[j]=min(up,left);
                }
            }
            p=c;
        }
        return p[m-1];
    }
};

// SINGLE ARRAY TABULATION   
// Time: O(N*m)
// Space: O(M)
