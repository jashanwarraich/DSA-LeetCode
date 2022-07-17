// Q181 https://leetcode.com/problems/super-egg-drop/submissions/

// Recursion
// Time: O(2^n)
// Space: O(n) 
class Solution {
    int func(int e, int f){
        if(f==0||f==1) return f;
        if(e==1) return f;
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp=1+max(func(e-1,k-1),func(e,f-k));
            mn=min(mn,temp);
        }
        return mn;
            
    }
public:
    int superEggDrop(int e, int f) {
        return func(e,f);
    }
};


// Memorisation
// Time: O(N*m*m)
// Space: O(N*M)+O(N) = auxiliary stack space+ dp
class Solution {
    int func(int e, int f,vector<vector<int>> &dp){
        if(f==0||f==1) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp=1+max(func(e-1,k-1,dp),func(e,f-k,dp));
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
            
    }
public:
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e+1,vector<int>(f+1,-1));
        return func(e,f,dp);
    }
};


// DP
// Time: O(N*m*m)
// Space: O(N*M)
class Solution {
public:
    int superEggDrop(int eg, int fl) {
        vector<vector<int>> dp(eg+1,vector<int>(fl+1,0));
        for(int i=1;i<=eg;i++){
            dp[i][0]=0;
            dp[i][1]=1;
        }
        for(int i=1;i<=fl;i++) dp[1][i]=i;
        for(int e=2;e<=eg;e++){
            for(int f=2;f<=fl;f++){
                int mn=INT_MAX;
                for(int k=1;k<=f;k++){
                    int temp=1+max(dp[e-1][k-1],dp[e][f-k]);
                    mn=min(mn,temp);
                }
                dp[e][f]=mn;
            }
        }
        return dp[eg][fl];
    }
};


// DP with Binary Search
// Time: O(N*m*logm)
// Space: O(2*M)
class Solution {
public:
    int superEggDrop(int eg, int fl) {
        vector<vector<int>> dp(eg+1,vector<int>(fl+1,0));
        for(int i=1;i<=eg;i++){
            dp[i][0]=0;
            dp[i][1]=1;
        }
        for(int i=1;i<=fl;i++) dp[1][i]=i;
        for(int e=2;e<=eg;e++){
            for(int f=2;f<=fl;f++){
            int low = 0, high = f, mn = INT_MAX;

            while(low <= high)
            {
                int mid = (low+high)/2;
                int a = dp[e-1][mid-1];
                int b = dp[e][f-mid];
                int temp = 1 + max(a, b);
                if(a > b)
                    high = mid-1;
                else
                    low = mid+1;
                mn = min(mn, temp);
            }
                dp[e][f]=mn;
            }
        }
        return dp[eg][fl];
    }
};
