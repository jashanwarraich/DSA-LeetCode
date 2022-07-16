// Q180 https://www.codingninjas.com/codestudio/problems/800284?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1




// Recursion
// Time: O(2^n)
// Space: O(n) 
int f(int ind,int n, vector<int> &p){
    if(ind==0)
        return p[0]*n;
    int nt=f(ind-1,n,p);
    int t=INT_MIN;
    int rl=ind+1; //rod length
    if(rl<=n)
        t=p[ind]+f(ind,n-rl,p);
    return max(t,nt);
}
int cutRod(vector<int> &p, int n){
    return f(n-1,n,p);
}


// Memorisation
// Time: O(N*m)
// Space: O(N*M)+O(N) = auxiliary stack space+ dp
int f(int ind,int n, vector<int> &p,vector<vector<int>> &dp){
    if(ind==0)
        return p[0]*n;
    if(dp[ind][n]!=-1) return dp[ind][n];
    int nt=f(ind-1,n,p,dp);
    int t=INT_MIN;
    int rl=ind+1; //rod length
    if(rl<=n)
        t=p[ind]+f(ind,n-rl,p,dp);
    return dp[ind][n]=max(t,nt);
}
int cutRod(vector<int> &p, int n){
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(n-1,n,p,dp);
}


// DP
// Time: O(N*m)
// Space: O(N*M)

int cutRod(vector<int> &p, int N){
    vector<vector<int>> dp(N,vector<int>(N+1,0));
    for(int n=0;n<N+1;n++) dp[0][n]=p[0]*n;
    for(int ind=1;ind<N;ind++){
        for(int n=0;n<=N;n++){
            int nt=dp[ind-1][n];
            int t=INT_MIN;
            int rl=ind+1; //rod length
            if(rl<=n)
                t=p[ind]+dp[ind][n-rl];
            dp[ind][n]=max(t,nt);
        }
    }
    
    return dp[N-1][N];
}


// TABULATION
// Time: O(N*m)
// Space: O(2*M)
int cutRod(vector<int> &p, int N){
//     vector<vector<int>> dp(N,vector<int>(N+1,0));
    vector<int> prev(N+1,0),cur(N+1,0);
    for(int n=0;n<N+1;n++) prev[n]=p[0]*n;
    for(int ind=1;ind<N;ind++){
        for(int n=0;n<=N;n++){
            int nt=prev[n];
            int t=INT_MIN;
            int rl=ind+1; //rod length
            if(rl<=n)
                t=p[ind]+cur[n-rl];
            cur[n]=max(t,nt);
        }
        prev=cur;
    }
    
    return prev[N];
}

// SINGLE ARRAY TABULATION   
// Time: O(N*m)
// Space: O(M)
int cutRod(vector<int> &p, int N){
//     vector<vector<int>> dp(N,vector<int>(N+1,0));
    vector<int> prev(N+1,0);
    for(int n=0;n<N+1;n++) prev[n]=p[0]*n;
    for(int ind=1;ind<N;ind++){
        for(int n=0;n<=N;n++){
            int nt=prev[n];
            int t=INT_MIN;
            int rl=ind+1; //rod length
            if(rl<=n)
                t=p[ind]+prev[n-rl];
            prev[n]=max(t,nt);
        }
//         prev=cur;
    }
    
    return prev[N];
}