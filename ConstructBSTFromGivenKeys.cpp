// Q133 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Time: O(n)
// Space: O(n)


class Solution {
public:
    TreeNode* helper(vector<int> &arr, int s, int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* nr=new TreeNode(arr[mid]);
        nr->left=helper(arr,s,mid-1);
        nr->right=helper(arr,mid+1,e);
        return nr;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0,nums.size()-1);
    }
};