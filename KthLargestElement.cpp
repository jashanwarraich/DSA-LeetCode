// Q70 https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0)
            return -1;
        priority_queue<int> pq;
        // priority_queue<int,vector<int>,greater<int>> pq; MIN HEAP
        for(auto i: nums)
            pq.push(i);
        int res=INT_MIN;
        while(k--){
            res=pq.top();
            pq.pop();
        }
        return res;
    }
};