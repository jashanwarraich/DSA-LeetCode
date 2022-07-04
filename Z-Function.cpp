// Q98 https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string a, string b) {
        //a=haystack AND b=needle
        int i=0,j=0;
        while(i<a.size()){
            if(a[i]==b[j]) i++,j++;
            else{
                i=i-j+1;
                j=0;
            }
            if(j==b.size()) return (i-j);
        }
        return -1;
        
    }
};