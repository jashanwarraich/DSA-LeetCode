// Q183 https://www.codingninjas.com/codestudio/problems/873266?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



// Recursion
// Time: Exponential
// Space: O(n) 
#include<bits/stdc++.h>
bool ispalindrome(int s,int e, string &str){
    while(s<e){
        if(str[s]!=str[e]) return false;
        s++,e--;
    }
    return true;
}
int f(int i,int n,string &str){
    if(i==n) return 0;
    int mc=INT_MAX;
    for(int j=i;j<n;j++){
        if(ispalindrome(i,j,str)){
            int cost=1+f(j+1,n,str);
            mc=min(mc,cost);
        }
    }
    return mc;
}
int palindromePartitioning(string str) {
    int n=str.size();
    return f(0,n,str)-1;    
}


// Memorisation
// Time: O(N*N)
// Space: O(N)+O(N) = auxiliary stack space+ dp
#include<bits/stdc++.h>
bool ispalindrome(int s,int e, string &str){
    while(s<e){
        if(str[s]!=str[e]) return false;
        s++,e--;
    }
    return true;
}
int f(int i,int n,string &str,vector<int> &dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int mc=INT_MAX;
    for(int j=i;j<n;j++){
        if(ispalindrome(i,j,str)){
            int cost=1+f(j+1,n,str,dp);
            mc=min(mc,cost);
        }
    }
    return dp[i]=mc;
}
int palindromePartitioning(string str) {
    int n=str.size();
    vector<int> dp(n,-1);
    return f(0,n,str,dp)-1;    
}


// DP AND TABULATION
// Time: O(N*N)
// Space: O(2*N)
#include<bits/stdc++.h>
bool ispalindrome(int s,int e, string &str){
    while(s<e){
        if(str[s]!=str[e]) return false;
        s++,e--;
    }
    return true;
}

int palindromePartitioning(string str) {
    int n=str.size();
    vector<int> dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int mc=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,str)){
                int cost=1+dp[j+1];
                mc=min(mc,cost);
            }
        }
        dp[i]=mc;
    }
    return dp[0]-1;    
}

