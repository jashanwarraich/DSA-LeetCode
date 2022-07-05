// Q100 https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(n)

#include<bits/stdc++.h>
vector<int> genlps(string s){
    int n=s.size();
    vector<int>lps(n);
    int i=1,len=0;
    while(i<n){
        if(s[i]==s[len]) lps[i++]=++len;
        else if(len) len=lps[len-1];
        else lps[i++]=0;
    }
    return lps;
}

int minCharsforPalindrome(string s) {
	string r=s;
    reverse(r.begin(),r.end());
    string ns=s+'$'+r;
    auto lps=genlps(ns);
    return s.size()-lps.back();
}
