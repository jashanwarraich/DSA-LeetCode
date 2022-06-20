//https://leetcode.com/problems/longest-consecutive-sequence/submissions/


//Using Set
class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        int s=n.size();
        if(s==0){
            return 0;
        }
        set<int> hset;
        for(int i:n){
            hset.insert(i);
        }
        int res=1;
        for(int i:hset){
            if(!hset.count(i-1)){
                int cc=1;
                int j=1;
                while(hset.count(i+j)>0){ 
                    cc++;
                    j++;
                }
                res=max(res,cc);
            }
        }
        return res;
    }
};




//Using Hashmap
class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        int s=n.size();
        if(s==0){
            return 0;
        }
        unordered_map<int,int> m;
        for(int i=0;i<s;i++){
            m[n[i]]++;
        }
        int res=1;
        for(int i=0;i<s;i++){
            if(m[n[i]-1]<=0){
                int cc=1;
                int j=1;
                while(m[n[i]+j]>0){ 
                    cc++;
                    j++;
                }
                res=max(res,cc);
            }
        }
        return res;
    }
};