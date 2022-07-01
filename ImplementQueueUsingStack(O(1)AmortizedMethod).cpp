// Q78 https://leetcode.com/problems/implement-queue-using-stacks/


// Time: push- O(1)
//       pop- O(1) {amortised i.e. in most of the cases it is O(1)}
// Space: O(2*n)
class MyQueue {
    stack<int> in;
    stack<int> op;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(op.empty()){
            while(!in.empty()){
                op.push(in.top());
                in.pop();
            }
        }
        int ans=op.top();
        op.pop();
        return ans;
    }
    
    int peek() {
        if(op.empty()){
            while(!in.empty()){
                op.push(in.top());
                in.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        return in.empty()&&op.empty();
    }
};
