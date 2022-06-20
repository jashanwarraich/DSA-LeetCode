// Q23 https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &n, int B){
    int xorr=0;
    int c=0;
    unordered_map<int,int>m;
    for(int i:n){
        xorr=xorr^i;
        if(xorr==B)
            c++;
        if(m.find(B^xorr)!=m.end()){
            c+=m[B^xorr];
        }
        m[xorr]++;
    }
    return c;
}