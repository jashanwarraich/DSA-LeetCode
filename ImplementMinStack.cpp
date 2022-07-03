// Q87 https://leetcode.com/problems/min-stack/

// Time: O(1)

class MinStack {
    stack<long long> s;
    long long mi;
public:
    MinStack() {
        while(!s.empty()) s.pop();
        mi=INT_MAX;
    }
    
    void push(int val) {
        long long v=val;
        if(s.empty()){
            s.push(v);
            mi=v;
        }
        else{
            if(mi>v){
                s.push(2*v*1LL-mi);
                mi=v;
            }
            else{
                s.push(v);
            }
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        long long el=s.top();
        s.pop();
        if(el<mi)
            mi=2*mi-el;
    }
    
    int top() {
        if(s.empty())
            return -1;
        long long el=s.top();
        if(el<mi)
            return mi;
        else return el;
    }
    
    int getMin() {
        return mi;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */