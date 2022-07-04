// Q96 https://leetcode.com/problems/longest-common-prefix/

// Time: O(n)
// Space: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        bool flag=true;
        int i=0;
        while(flag){
            for(int j=0;j<n;j++){
                if((i>s[j].size())||(s[j][i]!=s[0][i])){
                     flag=false; 
                     break;
                }
            }
            i++;
        }
        return s[0].substr(0,i-1);
    }
};