//https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
    // Write your code here 
    vector <int> b(n+1);
    pair<int,int> p;
    for(int i=0;i<n+1;i++){
        b[i]=0;
    }
    for(int i=0;i<n;i++){
        b[a[i]]++;
    }
    for(int j=1;j<n+1;j++){
        if(b[j]==0){
            p.first=j;
        }
         if(b[j]==2){
            p.second=j;
        }
        
    }
    return p;
    
    
}

