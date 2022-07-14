// Q170 https://leetcode.com/problems/maximum-product-subarray/

//Approach1 (better)
// Time: O(N)
// Space: O(1)

//  motivated by Kandane’s algorithm
class Solution {
public:
    int maxProduct(vector<int>& a) {
        int res=a[0], p1=a[0],p2=a[0];
        for(int i=1;i<a.size();i++){
            int t=max({a[i],p1*a[i],p2*a[i]});
            p2=min({a[i],p1*a[i],p2*a[i]});
            p1=t;
            res= max(res,p1);
        }
        return res;
    }
};







//Approach2 
// Time: O(N)
// Space: O(1)
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int maxLeft = nums[0];
    int maxRight = nums[0];
    
    int prod = 1;
    
    bool zeroPresent =  false;
    
    for(auto i:nums) {
        prod *= i;
        if(i == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxLeft = max(maxLeft,prod);
    }
    
    prod = 1;
    
    for(int j=nums.size()-1;j>=0;j--) {
        prod *= nums[j];
        if(nums[j] == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxRight = max(maxRight,prod);
    }
    
    if(zeroPresent) return max(max(maxLeft,maxRight),0);
    return max(maxLeft,maxRight);
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}