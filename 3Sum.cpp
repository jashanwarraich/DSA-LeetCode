// Q39 https://leetcode.com/problems/3sum/

// Time: O(n*n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> r;
        sort(num.begin(), num.end());
        int s=num.size();
        for(int i=0;i<s-2;i++){
            if(i==0||num[i]!=num[i-1]){
                int j=i+1, k=s-1;
                while(j<k){
                    int sum=num[i]+num[j]+num[k];
                    if(sum==0){
                        r.push_back({num[i],num[j],num[k]});
                        while(j<k&&num[j]==num[j+1])j++;
                        while(j<k&&num[k]==num[k-1])k--;
                        j++;k--;
                    }
                    else if(sum>0)k--;
                    else j++;
                }
            }
        }
        return r;
    }
};