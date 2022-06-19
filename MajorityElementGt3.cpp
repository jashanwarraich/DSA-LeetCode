// https://leetcode.com/problems/majority-element-ii/submissions/

// O(nLogn)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        
        
        int n=arr.size();
        unordered_map<int,int> h;
        for(int i=0;i<n;i++){
            h[arr[i]]++;
        }

        vector <int> v;
        for(int i=0;i<n;i++){
            if(h[arr[i]]>n/3 && (!v.size() || v[v.size()-1]!=arr[i])){
                 // && v.back()!=arr[i]
                v.push_back(arr[i]);
            }
        }
        
        
        return v;
    }
};