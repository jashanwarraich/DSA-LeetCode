// Q76 https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

class Queue {
    int *a;
    int cnt;
    int cap;
    int f;
    int r;
public:
    Queue() {
        a= new int[100010];
        cnt=0;
        cap=100010;
        f=0;
        r=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return cnt==0;
    }

    void enqueue(int data) {
        if(cnt==cap) return;
        a[r%cap]=data;
        r++;
        cnt++;
    }

    int dequeue() {
        if(cnt==0) return -1;
        int ans=a[f];
        a[f%cap]=-1;
//         f=(f+1)%cap;
        f++;
        cnt--;
        return ans;
    }

    int front() {
        if(cnt!=0) return a[f];
        return -1;
    }
};