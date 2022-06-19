// https://leetcode.com/problems/majority-element/

// O(n)
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        
        int count=0;
        int cand=0;
        for(int i:arr){
            if(count==0) cand=i;
            if(cand==i) count++;
            else count--;
        }

        return cand;
    }
};


// O(nlogn) hashmap, it will be On when using array as hashmap

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> h;
        for(int i=0;i<n;i++){
            h[arr[i]]++;
        }
        int m=h[arr[0]];
        int a=arr[0];
        for(int i=0;i<n;i++){
            if(h[arr[i]]>m){
                m=h[arr[i]];
                a=arr[i];
            }
        }
        return a;
    }
};