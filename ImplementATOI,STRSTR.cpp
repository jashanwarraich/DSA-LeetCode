// Q95 https://leetcode.com/problems/roman-to-integer/

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        long long ans=0;
        while(i<n&&s[i]==' ') i++;
        int sign=1;
        if(s[i]=='-') {sign=-1; i++;}
        else if(s[i]=='+') i++;
        while(i<n&&isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX&& sign==1) return INT_MAX;
            if(ans>INT_MAX&& sign==-1) return INT_MIN;
            i++;
        }
        return ans*sign;
    }
};