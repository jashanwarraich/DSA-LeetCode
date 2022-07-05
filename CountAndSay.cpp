// Q102 https://leetcode.com/problems/count-and-say/

// Time: O(n*n)
// Space: O(n) 

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string s="11";
        for(int i=3;i<=n;i++){
            string t="";
            s=s+"$";
            int c=1;
            for(int j=1;j<s.size();j++){
                if(s[j]!=s[j-1]){
                    t=t+to_string(c)+s[j-1];
                    c=1;
                }
                else c++;
            }
            s=t;
        }
        return s;
    }
};