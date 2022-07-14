// Q172 https://leetcode.com/problems/longest-common-subsequence/

// Memorisation
// Time: O(N*m)
// Space: O(N*M)+O(N*M) = auxiliary stack space+ dp

class Solution {
public:
    int f(int i,int j,string &s1, string&s2,vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= 1+ f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n-1,m-1,s1,s2,dp);
    }
};


// DP
// Time: O(N*m)
// Space: O(N*M)
class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int j=0;j<m+1;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]= 1+ dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};


// TABULATION
// Time: O(N*m)
// Space: O(2*M)
class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>p(m+1,0);
        vector<int>c(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) c[j]= 1+ p[j-1];
                else 
                    c[j]=max(p[j],c[j-1]);
            }
            p=c;
        }
        return p[m];
    }
};