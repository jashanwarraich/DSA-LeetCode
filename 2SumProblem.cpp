// https://leetcode.com/problems/two-sum/submissions/

// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        unordered_map<int,int> m;
        int s=a.size();
        vector<int>v;
        for(int i=0;i<s;i++){
            if(m.find(t-a[i])!=m.end()){
                v.push_back(m[t-a[i]]);
                v.push_back(i);
                return v;
            }
            m[a[i]]=i;
        }
        return v;
    }
};


