// Q62 https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(r)+O(rlogc)
// Space: O(1)
// #include<climits>
// #include<algorithm>
#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &m){
    int r=m.size();
    int c=m[0].size();
    int mi=INT_MAX, ma=INT_MIN;
    for(int i=0;i<r;i++){
        mi=min(mi,m[i][0]);
        ma=max(ma,m[i][c-1]);
    }
//     cout<<mi<<ma<<endl;
    int des=(r*c+1)/2;
    while(ma>mi){
        int mid=mi+(ma-mi)/2;
        int place=0;
        for(int i=0;i<r;i++){
            place+=upper_bound(m[i].begin(),m[i].begin()+c,mid)-m[i].begin();
        }
        if(place<des)
            mi=mid+1;
        else
            ma=mid;
     }
    return mi;
}