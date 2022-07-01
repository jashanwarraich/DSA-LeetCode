// Q80 https://leetcode.com/problems/next-greater-element-ii/

// Time: O(2n+2n)
// Space: O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        stack <int> s;
        int n=a.size();
        vector<int> nge(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty()&&s.top()<=a[i%n])
                s.pop();
            if(n>i){
                if(!s.empty())
                    nge[i]=s.top();
                // else
                //     nge.push_back(-1);
            }
            s.push(a[i%n]);
        }
        return nge;
    }
};