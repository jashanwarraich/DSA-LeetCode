//Q24 https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

// O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string n) {
        unordered_map <int,int> m;
        int s=n.length();
        int len=0,l=0,r=0;
        while(r<s){
            if(m.find(n[r])!=m.end()){
                l=max(m[n[r]]+1,l);
            }
            m[n[r]]=r;
            len=max(r-l+1,len);
            r++;
        }
        return len;
    }
};