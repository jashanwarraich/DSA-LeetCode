// QEXTRA https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Brute force 
vector<int> maxXorQueries(vector<int> &a, vector<vector<int>> &q){
    vector<int> ans;
    int n=a.size();
    for(int i=0;i<q.size();i++){
//         int r=-1;
        int ma=-1;
        for(int j=0;j<n;j++){
           if(a[j]<=q[i][1]){
//                int val=a[j]^q[i][0];
               ma=max(ma,a[j]^q[i][0]);
//                cout<<val<<endl;
           }
        }
        ans.push_back(ma);
    }
    return ans;
}