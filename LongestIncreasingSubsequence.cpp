// Q171 https://leetcode.com/problems/longest-increasing-subsequence/

// Memoization
// Time: O(N*N)
// Space: O(N*N)+O(N)

class Solution {
    int f(int ind,int prev,vector<int>& a, int n,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int l=f(ind+1,prev,a,n,dp);
        if(prev==-1||a[ind]>a[prev]){
            l=max(l,1+f(ind+1,ind,a,n,dp));
        }
        return dp[ind][prev+1]=l;
    }
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,a,n,dp);
    }
};



//BINARY SEARCH
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> temp;
        temp.push_back(a[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(a[i]>temp.back()){
                temp.push_back(a[i]);
                len++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();//next greater element than a[i]
                temp[ind]=a[i];
            }
        }
        return temp.size();
    }
};





//DP
//Using the logic used in the MaximumSumIncreasingSubsequence


class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size(); 
        vector<int> msis(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]&&msis[i]<msis[j]+1){
                    msis[i]=msis[j]+1;
                }
            }
           }
        int ans=msis[0];
        for(auto it: msis)
            ans=max(ans,it);
        return ans;
    
    }
};


