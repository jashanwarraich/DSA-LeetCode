// Q55 https://leetcode.com/problems/permutations/

// Time: O(n!*n)
// Space: O(1)

class Solution {
public:
    void recf(int ind, vector<int>& nums, vector<vector<int>> &ans){
        if(nums.size()==ind){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            recf(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recf(0,nums,ans);
        return ans;
    }
};


// Space: O(n) solution also possible where we dont use the swap function but use a extra freq array to check if the number is already used or not

// Link(Other approach): https://youtu.be/YK78FU5Ffjw?list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&t=1081