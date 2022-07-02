// Q85 https://leetcode.com/problems/largest-rectangle-in-histogram/

//APPROACH 1
// Time: O(n+n)
// Space: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack <int> s; 
        int ma=0;
        for(int i=0;i<=n;i++){
            while(!s.empty()&&(i==n||h[s.top()]>=h[i])){
                int he=h[s.top()];
                s.pop();
                int width;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                ma=max(ma,(he*width));
            }
            s.push(i);
        }
        return ma;
    }
};


//APPROACH 2
// Time: leftsmaller O(n+n) + rightsmaller O(n+n) + calculate answer O(n)
// Space: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int rs[n];
        int ls[n];
        stack <int> s; 
        for(int i=0;i<n;i++){
            while(!s.empty()&&h[s.top()]>=h[i])
                s.pop();
            if(s.empty()) ls[i]=0;
            else ls[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&h[s.top()]>=h[i])
                s.pop();
            if(s.empty()) rs[i]=n-1;
            else rs[i]=s.top()-1;
            s.push(i);
        }
        int ma=0;
        for(int i=0;i<n;i++)
            ma=max(ma,h[i]*(rs[i]-ls[i]+1));
        return ma;
    }
};


//APPROACH 3
// Brute Force
// O(n*n)
// calculate leftsmaller and rightsmaller for every element