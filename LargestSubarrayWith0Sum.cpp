//Q22  https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > n) {
    int s=n.size();
    unordered_map <int,int>m;
    int sum=0, maxi=0;
    for(int i=0;i<s;i++){
        sum+=n[i];
        if(sum==0)
            maxi=i+1;
        else{
            if(m.find(sum)!=m.end()){
                maxi=max(maxi,i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
    }
    return maxi;
}