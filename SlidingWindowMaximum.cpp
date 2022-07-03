// Q86 https://leetcode.com/problems/sliding-window-maximum/

// Time: O(n)+O(n) amortised
// Space: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        deque<int> q;
         vector<int> v;
        for(int i=0;i<n;i++){
            while(!q.empty()&&q.front()==i-k)
                q.pop_front();
            while(!q.empty()&&a[i]>=a[q.back()])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1) v.push_back(a[q.front()]);
        }
        return v;
    }
};
