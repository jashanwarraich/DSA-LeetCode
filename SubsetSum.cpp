// Q179 https://www.codingninjas.com/codestudio/problems/1550954?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Recursion
// Time: O(2^n)
// Space: O(n) 
bool f(int ind, int k, vector<int> &a){
    if(k==0) return true;
    if(ind==0) return a[0]==k;
    bool nt=f(ind-1,k,a);
    bool t=false;
    if(a[ind]<=k) t=f(ind-1,k-a[ind],a);
    return t||nt;
}
bool subsetSumToK(int n, int k, vector<int> &a) {
    return f(n-1,k,a);
}

// Memorisation
// Time: O(N*m)
// Space: O(N*M)+O(N) = auxiliary stack space+ dp
bool f(int ind, int k, vector<int> &a,vector<vector<int>> &dp){
    if(k==0) return true;
    if(ind==0) return a[0]==k;
    if(dp[ind][k]!=-1) return dp[ind][k]; 
    bool nt=f(ind-1,k,a,dp);
    bool t=false;
    if(a[ind]<=k) t=f(ind-1,k-a[ind],a,dp);
    return dp[ind][k]=t||nt;
}
bool subsetSumToK(int n, int k, vector<int> &a) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,a,dp);
}

// DP
// Time: O(N*m)
// Space: O(N*M)

bool subsetSumToK(int n, int k, vector<int> &a) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int ind=0;ind<n;ind++) dp[ind][0]=true;
    dp[0][a[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int tar=1;tar<=k;tar++){
                bool nt=dp[ind-1][tar];
                bool t=false;
                if(a[ind]<=tar) t=dp[ind-1][tar-a[ind]];
                dp[ind][tar]=t||nt;
        }
    }
    return dp[n-1][k];
}

// TABULATION
// Time: O(N*m)
// Space: O(2*M)

bool subsetSumToK(int n, int k, vector<int> &a) {
//     vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    vector<bool> p(k+1,false);
    vector<bool> c(k+1,false);
    p[0]=c[0]=true;
    p[a[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int tar=1;tar<=k;tar++){
                bool nt=p[tar];
                bool t=false;
                if(a[ind]<=tar) t=p[tar-a[ind]];
                c[tar]=t||nt;
        }
        p=c;
    }
    return p[k];
}

