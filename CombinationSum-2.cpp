// Q52 https://leetcode.com/problems/combination-sum-ii/

// Time: 2^n * k
// Space: k * x
// k=avg len of every combination
// t= target
// x= no of combinations 

class Solution {
public:
    void recf(int ind, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans, int t) {
        if(t==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i!=ind&&nums[i]==nums[i-1]) continue;
            if(nums[i]>t) break;
            ds.push_back(nums[i]);
            recf(i+1,nums,ds,ans,t-nums[i]);
            ds.pop_back();
        }
        // recf(ind+1,nums,ds,ans,t);
        
    }    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        recf(0,nums,ds,ans,t);
        return ans;
    }
};