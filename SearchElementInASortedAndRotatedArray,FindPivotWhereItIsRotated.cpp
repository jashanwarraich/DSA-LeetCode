// Q64 https://leetcode.com/problems/search-in-rotated-sorted-array/

// Time: Olog(n)

class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==t) return mid;
            if(nums[l]<=nums[mid]){
                if(t>=nums[l]&&t<=nums[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else{
               if(t>=nums[mid]&&t<=nums[h])
                    l=mid+1;
                else
                    h=mid-1;
            
            }
        }
        return -1;
    }
};
