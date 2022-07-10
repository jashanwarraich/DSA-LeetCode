// Q146 https://leetcode.com/problems/find-median-from-data-stream/

// Time: addNum - O(logN) 
//      findMedian - O(1)

class MedianFinder {
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    int cnt=0;
public:
    MedianFinder() {
        maxh=priority_queue<int>();
        minh=priority_queue<int,vector<int>,greater<int>>();

    }
    
    void addNum(int num) {
        cnt%2==0?maxh.push(num):minh.push(num);
        cnt++;
        int l=maxh.empty()?INT_MIN:maxh.top();
        int r=minh.empty()?INT_MAX:minh.top();
        if(l>r){
            maxh.pop(); maxh.push(r);
            minh.pop(); minh.push(l);
        }
    }
    
    double findMedian() {
        if(cnt%2==0)
            return (double)(maxh.top()+minh.top())/2.0; 
        else
            return maxh.top();
    }
};
