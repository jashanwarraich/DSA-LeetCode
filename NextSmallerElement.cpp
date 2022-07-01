// Q82 https://www.codingninjas.com/codestudio/problems/1112581?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(2n+2n)
// Space: O(n)
#include<stack>
vector<int> nextSmallerElement(vector<int>& a,int n) {
    stack <int> s;
    vector<int> nge(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&s.top()>=a[i])
            s.pop();
        if(!s.empty())
            nge[i]=s.top();
        s.push(a[i]);
    }
        return nge;
}
