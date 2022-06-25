// Q53 https://leetcode.com/problems/palindrome-partitioning/


class Solution {
public:
    bool ispalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    
    void recf(int ind, string s,vector<vector<string>> &ans, vector<string> &ds){
        if(ind==s.size()){
            ans.push_back(ds);
            return;
        }    
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                recf(i+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        recf(0,s,ans,ds);
        return ans;
    }
};