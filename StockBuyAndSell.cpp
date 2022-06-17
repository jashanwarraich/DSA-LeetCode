// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int l = INT_MAX;
        int m = 0;
        int s = p.size();
        for (int i = 0; i < s; i++)
        {
            l = min(p[i], l);
            m = max(m, p[i] - l);
        }
        return m;
    }
};

// N2 appproach

// class Solution {
// public:
//     int maxProfit(vector<int>& p) {
//        int r=0;
//         int m=INT_MIN;
//         for(int i=0;i<p.size();i++){
//             for(int j=i;j<p.size();j++){
//                 if(p[j]-p[i]>m)m=p[j]-p[i];
//             }
//         }
//         return m;
//     }
// };