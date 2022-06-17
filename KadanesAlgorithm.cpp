// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &a)
    {
        int s = a[0];
        int res = a[0];
        int n = a.size();
        for (int i = 1; i < n; i++)
        {
            if (s < 0)
                s = 0;
            s += a[i];
            if (res < s)
                res = s;
        }
        return res;
    }
};