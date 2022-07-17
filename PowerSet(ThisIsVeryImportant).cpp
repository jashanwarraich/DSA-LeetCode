// Q189 https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1

//Time: O(2^N*N)

vector<vector<int>> pwset(vector<int>v){
    int n=v.size();
    vector<vector<int>> ans;
    for(int num=0;num<(1<<n);num++){ //1<<n==2^n
        vector<int> cur;
        for(int i=0;i<n;i++){
            if(num&1<<i){
                cur.push_back(v[i]);
            }
        }
        ans.push_back(cur);
    }
    return ans;
}
