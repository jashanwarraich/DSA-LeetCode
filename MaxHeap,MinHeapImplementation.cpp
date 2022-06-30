// Q69 https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: Insertion (logn) 
      // Deletion (logn)
// Space: O(1)


void insert(vector<int> &pq, int el){
    pq.push_back(el);
    int ci=pq.size()-1;
//     int pi=(ci-1)/2;
    while(ci>0){
        int pi=(ci-1)/2;
        if(pq[pi]>pq[ci]){
            swap(pq[pi],pq[ci]);
        }
        else
            break;
        ci=pi;
    }    
}

int removeMin(vector<int> &pq){
//     if(pq.size()==0) return 0;
    int ans=pq[0];
    pq[0]=pq[pq.size()-1];
    pq.pop_back();
    int pi=0;
    int lc=(pi*2)+1;
    int rc=(pi*2)+2;
    while(lc<pq.size()){
        int mini=pi;
        if(pq[lc]<pq[mini]){
//             swap(pq[lc],pq[pi]);
            mini=lc;
        }
        if(rc<pq.size()&&pq[rc]<pq[mini]){
//             swap(pq[rc],pq[pi]);
            mini=rc;
        }
        if(mini==pi)
            break;
        swap(pq[mini],pq[pi]);
        pi=mini;
        lc=(pi*2)+1;
        rc=(pi*2)+2;
    }
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> res;
    vector<int> pq;
    for(int i=0;i<n;i++){
        if(q[i][0]==0)
            insert(pq,q[i][1]);
        if(q[i][0]==1&&pq.size()!=0)
            res.push_back(removeMin(pq));
    }
    return res;
}

