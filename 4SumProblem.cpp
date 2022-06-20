// https://leetcode.com/problems/4sum/



//On3
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& n, int t) {
        int s=n.size();
        vector<vector<int>> v;
        sort(n.begin(),n.end());
        
        for(int i=0;i<s;i++){
            // cout<<n[i];
            for(int j=i+1;j<s;j++){
                long long nt=(long long)t-(n[i]+n[j]); //LL because signed integer overflow: -294967296 - 2000000000 cannot be represented in type 'int' 
                int l=j+1,r=s-1;
                while(l<r){
                    if(n[l]+n[r]>nt){
                        r--;
                    }
                    else if(n[l]+n[r]<nt){
                        l++;
                    }
                    else{
                        v.push_back({n[i],n[j],n[l],n[r]});
                        while(l<r&&n[l]==v[v.size()-1][2]) ++l;
                        while(r>l&&n[r]==v[v.size()-1][3]) r--;
                    }
                }
                while(j+1<s && n[j]==n[j+1])j++;
            }
            while(i+1<s && n[i]==n[i+1])i++;

            
        }
        return v;
    }
};