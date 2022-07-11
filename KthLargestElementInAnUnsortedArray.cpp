// Q150 https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/

// Time: O(NlogN) //confirm
// Space:O(N)

class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(i<k) q.push(a[i]);
            else{
                if(q.top()<a[i]){
                    q.pop();
                    q.push(a[i]);
                }
            }
        }
        return q.top();
    }
};
