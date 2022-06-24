// Q44 https://www.codingninjas.com/codestudio/problems/799400?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


// Time: O(nLog(n))
// Space: O(1)
int calculateMinPatforms(int at[], int dt[], int n) {
    int p=1, res=1;
    int i=1, j=0;
    sort(at,at+n);
    sort(dt,dt+n);
    while(i<n&&j<n){
        if(at[i]<=dt[j]){
            i++;
            p++;
        }
        else if(at[i]>dt[j]){
            j++;                  
            p--;
        }
        if(p>res) res=p;
    }
    
    return res;
}