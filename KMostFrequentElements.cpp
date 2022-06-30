// Q74 https://leetcode.com/problems/top-k-frequent-elements/


// Time: O(d log d), where d is the count of distinct elements in the array. To sort the array O(d log d) time is needed.
// Space: O(d), where d is the count of distinct elements in the array. To store the elements in HashMap O(d) space complexity is needed.
class Solution {
public:
    static bool compare(pair<int,int> p1,pair<int,int> p2){ //was giving compile time error without static keyword
        if(p1.second==p2.second)
            return p1.first>p2.first;
        return p1.second>p2.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        // sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> v(m.begin(),m.end());
        
        sort(v.begin(),v.end(),compare);
        for(int j=0;j<k;j++){
            ans.push_back(v[j].first);
        }
        return ans;
    }
};


// Time: O(k log d + d), where d is the count of distinct elements in the array
// Space: O(d) 

class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> p1,pair<int,int> p2){
            if(p1.second==p2.second)
                return p1.first<p2.first;    // difference in condition of both the approaches
            return p1.second<p2.second;       // Here also
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        // sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> p(m.begin(),m.end());
        for(int j=0;j<k;j++){
            ans.push_back(p.top().first);
            p.pop();
        }
        return ans;
    }
};