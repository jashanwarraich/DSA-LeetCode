// Q40 https://leetcode.com/problems/trapping-rain-water/

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int l=0,r=n-1,lm=0,rm=0,res=0;
        while(l<=r){
            if(h[l]<=h[r]){
                if(h[l]>lm)lm=h[l];
                else res+=lm-h[l];
                l++;
            }
            else{
                if(h[r]>rm)rm=h[r];
                else res+=rm-h[r];
                r--;
            }
        }
        return res;
    }
};