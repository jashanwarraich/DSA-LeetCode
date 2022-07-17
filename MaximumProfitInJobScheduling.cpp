// Q184 https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


//Time: O(nlog(n)) + O(n*m) m=max deadine
//Space: O(m)
#include<algorithm>

bool sortcol(const vector<int> &v1,const vector<int> &v2){
    return v1[1]>v2[1];
}

int jobScheduling(vector<vector<int>> &jobs){
    int n=jobs.size(), maxp=0;
    sort(jobs.begin(),jobs.end(),sortcol);

    int md=0; // max deadline
    for(int i=0;i<n;i++){
        md=max(md,jobs[i][0]);
    }
    int slot[md+1];
    for(int i=0;i<md+1;i++)
        slot[i]=-1;
    for(int i=0;i<n;i++){
        for(int j=jobs[i][0];j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                maxp+=jobs[i][1];
                break;
            }
        }
    }
    return maxp;
}
