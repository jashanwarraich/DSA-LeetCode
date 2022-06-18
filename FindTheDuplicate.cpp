//https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& n) {
        
        int f=n[0],s=n[0];
        do{
            s=n[s];
            f=n[n[f]];
        }while(s!=f);

        f=n[0];
        while(s!=f){
            s=n[s];
            f=n[f];
        }
        return s;
    }
};