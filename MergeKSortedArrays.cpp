// Q73 https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<queue>
// #include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&a, int k)
{
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            p.push(a[i][j]);
        }
    }
    while(!p.empty()){
        ans.push_back(p.top());
        p.pop();
    }
    return ans;
}




// same solution just read the comments in the solution below
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>>p;
   for(int i=0;i<input.size();i++){
       for(int j=0;j<input[i]->size();j++){ //SEE THE DIFF BECAUSE OF POINTER INPUT IN FUNCTION
           p.push(input[i]->at(j)); // HERE ALSO
       }
   }
   // int i=0;
  int s=p.size();
    vector<int> v;
    
   for(int i=0;i<s;i++){
       v.push_back(p.top());
       p.pop();
   }
    return v;
}
