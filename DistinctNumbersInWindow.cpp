// Q149 https://www.interviewbit.com/problems/distinct-numbers-in-window/

// Time: O(N)
// Space:O(N)


vector<int> Solution::dNums(vector<int> &a, int k) {
    int n=a.size();
    vector<int> ans;
    unordered_map<int,int> m;
    int dc=0,i=0;
    for(i;i<k;i++){
        if(m[a[i]]==0) dc++;
        m[a[i]]++;
    }
    ans.push_back(dc);
    for(i=k;i<n;i++){
        if(m[a[i-k]]<=1){
            dc--;
        }
        m[a[i-k]]--;
        if(m[a[i]]==0) dc++;
        m[a[i]]++;
        
        ans.push_back(dc);
        
    }
    return ans;
}
