// Q60 https://leetcode.com/problems/word-break-ii/submissions/

// Time: O(N * (2 ^ (N - 1)))
// Space: O(N * (2 ^ (N - 1)))
// N= len of s
// Solution https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2

class Solution {
public:
    vector<string> recf( string s,int ind, unordered_set <string>  &dset,int n){
        if(ind==n) return {""};
        vector <string> sp, cp;
        string w="";
        for(int j=ind;j<n;j++){
            w.push_back(s[j]);
            if(dset.count(w)==0) continue;
            sp=recf(s,j+1,dset,n);
            for(int i=0;i<sp.size();i++){
                if(sp[i].size()!=0){
                    string t=w;
                    t.append(" ");
                    t.append(sp[i]);
                    sp[i]=t;
                }
                else{
                    sp[i]=w;
                }
            }
            for(int i=0;i<sp.size();i++)
                cp.push_back(sp[i]);
        }
        return cp;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> dset;
        for(int i=0;i<wordDict.size();i++)
            dset.insert(wordDict[i]);
        return recf(s,0,dset,s.size());
    }
};