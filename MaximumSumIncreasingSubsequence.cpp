// Q175 https://www.codingninjas.com/codestudio/problems/1112624?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


// DP
// Time: O(N*m)
// Space: O(N)
#include<bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &a, int n){
	vector<int> msis=a;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&msis[i]<msis[j]+a[i]){
                msis[i]=msis[j]+a[i];
            }
        }
       }
    int ans=msis[0];
    for(auto it: msis)
        ans=max(ans,it);
    return ans;
    
}
  