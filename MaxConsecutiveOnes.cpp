// Q42 https://leetcode.com/problems/max-consecutive-ones/

//Time: O(n)
// Space: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int res=0;
        int cm=0;
        for(int i:nums){
            if(i==0) cm=0;
            else cm++;
            res=max(res,cm);
        }
        return res;
    }
};