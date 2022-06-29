// Q66 https://www.codingninjas.com/codestudio/problems/1112629?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(log(min(n,m)))
// Space: O(1)

#include<climits>
int ninjaAndLadoos(vector<int> &nums1, vector<int> &nums2, int n1, int n2, int k) {
    if(n1>n2) return ninjaAndLadoos(nums2,nums1,n2,n1,k);
    int l=max(0,k-n2), h=min(k,n1);
    while(l<=h){
        int cut1=(l+h)>>1;
        int cut2=k-cut1;
        int l1=cut1==0?INT_MIN:nums1[cut1-1];
        int l2=cut2==0?INT_MIN:nums2[cut2-1];
        int r1=cut1==n1?INT_MAX:nums1[cut1];
        int r2=cut2==n2?INT_MAX:nums2[cut2];
        if(l1<=r2&&l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            h=cut1-1;
        }
        else{
            l=cut1+1;
        }
    }
    return 1;
}