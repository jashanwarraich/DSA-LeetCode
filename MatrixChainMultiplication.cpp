// Q176 https://www.codingninjas.com/codestudio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


// Recursion
// Time: exponential
// Space: O(n) 
int f(int i,int j,vector<int> &a){
    if(i==j) return 0;
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=a[i-1]*a[k]*a[j]+f(i,k,a)+f(k+1,j,a);
        if(steps<mini) mini=steps;
    }
    return mini;
}

int matrixMultiplication(vector<int> &a, int n){
    return f(1,n-1,a);
}

// Memorisation
// Time: O((N*N)*N)=N^3
// Space: O(N*N)+O(N) = auxiliary stack space+ dp
int f(int i,int j,vector<int> &a,vector<vector<int>> &dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=a[i-1]*a[k]*a[j]+f(i,k,a,dp)+f(k+1,j,a,dp);
        if(steps<mini) mini=steps;
    }
    return dp[i][j]=mini;
}

int matrixMultiplication(vector<int> &a, int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(1,n-1,a,dp);
}




// DP
// Time: O((N*N)*N)
// Space: O(N*N)
int matrixMultiplication(vector<int> &a, int n){
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=1;i<n;i++) dp[i][i]=0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=a[i-1]*a[k]*a[j]+dp[i][k]+dp[k+1][j];
                if(steps<mini) mini=steps;
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}
