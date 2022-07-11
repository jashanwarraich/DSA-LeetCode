// Q148 https://leetcode.com/problems/kth-largest-element-in-a-stream/

// Time: O(NlogN)
// Space:O(N)
class KthLargest {
    vector<int> v;
    int i;
public:
    KthLargest(int k, vector<int>& nums) {
        v.insert(v.end(),nums.begin(),nums.end());
        sort(v.begin(),v.end(),greater<int>());
        i=k-1;
    }
    
    int add(int val) {
        v.push_back(val);
        sort(v.begin(),v.end(),greater<int>());
        int ans=v[i];
        return ans;
    }
};


// Time: O(logN)
// Space:O(N)
class KthLargest {
    priority_queue <int, vector<int>, greater<int>> q;
    int i;
public:
    KthLargest(int k, vector<int>& nums) {
        i=k;
        for(int it:nums) add(it);
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>i) q.pop();
        return q.top();
    }
};
