// Q89 https://leetcode.com/problems/online-stock-span/


class StockSpanner {
    stack<pair<int,int>> s;
    int index=0;
public:
    StockSpanner() {
    }
    
    int next(int p) {
        if(s.empty()){
            s.push({p,index++});
            return 1;
        }
        while(!s.empty()&&p>=s.top().first){
            s.pop();
        }
        int ans=s.empty()?index+1:index-s.top().second;
        s.push({p,index++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */