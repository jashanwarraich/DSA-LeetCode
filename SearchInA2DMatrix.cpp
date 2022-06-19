//https://leetcode.com/problems/search-a-2d-matrix/


// O(log(n*m))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r=m.size();
        int c=m[0].size();
        int l=0;
        int h=(r*c)-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(m[mid/c][mid%c]==t){
                return 1;
            }
            else if(m[mid/c][mid%c]>t)
                h=mid-1;
            else
                l=mid+1;
        }
        return 0;
    }
};



// O(n)+O(m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r=m.size();
        int c=m[0].size();
        int i;
        bool res=false;
        if(m[0][0]>t)
            return res;
        for(i=0;i<r;i++){
            if(m[i][0]>t){
                break;
            }
        }
        i=i-1;
        for(int j=0;j<c;j++){
            if(m[i][j]==t){
                res=true;
                break;
            }
        }
        return res;
    }
}