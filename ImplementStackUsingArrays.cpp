// Q75 https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209

// Stack class.
class Stack {
    int *arr;
    int f;
    int totalsize;
public:
    
    Stack(int capacity) {
        arr=new int[capacity];
        totalsize=capacity;
        f=-1;
        
    }

    void push(int num) {
        arr[++f]=num;
    }

    int pop() {
        if(f!=-1) return arr[f--];
        else return -1;
    }
    
    int top() {
        if(f!=-1) return arr[f];
        else return -1;
    }
    
    int isEmpty() {
        return f==-1;
    }
    
    int isFull() {
        return f==totalsize-1;
    }
    
};