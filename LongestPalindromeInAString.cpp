// Q93 https://leetcode.com/problems/longest-palindromic-substring/

// Time: O(n*n)
// Space: O(n*n)

class Solution {
public:
    string longestPalindrome(string s) {
        int st=0,e=0,ans=INT_MIN;
        int n=s.size();
        int dp[n][n];
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    if(s[i]==s[j])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else{
                    if(s[i]==s[j]&&dp[i+1][j-1]==1)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                if(dp[i][j]==1&&ans<j-i+1){
                    st=i;
                    // e=j;
                    ans=j-i+1;
                }   
            }
        }
        return s.substr(st,ans);
        
    }
};