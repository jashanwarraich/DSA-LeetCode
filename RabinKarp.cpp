// Q97 https://leetcode.com/problems/repeated-string-match/submissions/

// Time:O(n)
// Space:O(1)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s="";
        int c=0;
        while(s.size()<b.size()){
            s+=a;
            c++;
        }
        if(s.find(b)<s.size())  //if(s.find(b)!= string::npos)
            return c;
        s+=a;
        c++;
        if(s.find(b)<s.size())
            return c;
        else 
            return -1;
    }
};