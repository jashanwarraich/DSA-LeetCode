// Q63 https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/

// Approach 1
// Time: O(n)
// Space: O(1)
// OR every element with the previous element, return it if its not 0  



// Approach 2: Binary Search
// Time: O(logn)
// Space: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-2;
        
        while(h>=l){
            int mid=(l+h)/2;     //int mid=(l+h)>>1; 
            if(nums[mid]==nums[mid^1])
                l=mid+1;
            else
                h=mid-1;
        }
        return nums[l];
    }
};