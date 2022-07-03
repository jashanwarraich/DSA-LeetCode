// Q90 https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Using next smaller elment
#include<stack>
#include<climits>
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> v(n,INT_MIN);
    stack <int> s;
    vector<int> rs(n,n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(!s.empty())
            rs[i]=s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    vector<int> ls(n,-1);
    for(int i=0;i<n;i++){
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(!s.empty())
            ls[i]=s.top();
        s.push(i);
    }
    for(int i=0;i<n;i++){
        int len=rs[i]-ls[i]-1;
        v[len-1]=max(v[len-1],a[i]);
    }
    for(int i=n-2;i>=0;i--)
        v[i]=max(v[i],v[i+1]);
    
    return v;
}





//Using slide window
#include<queue>
#include<climits>
int help(vector<int> &a, int k){
    int n=a.size();
    deque<int> q;
    int wmax=INT_MIN;
    for(int i=0;i<n;i++){
        if(!q.empty()&&q.front()==i-k)
            q.pop_front();
        while(!q.empty()&&a[i]<=a[q.back()])
            q.pop_back();
        q.push_back(i);
        if(i>=k-1) wmax=max(wmax,a[q.front()]);
    }
    return wmax;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(help(a,i));
    }
    return v;
}