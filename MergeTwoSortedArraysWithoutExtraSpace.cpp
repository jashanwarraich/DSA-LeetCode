//https://leetcode.com/problems/merge-sorted-array/submissions/

//GAP METHOD
//O(n*nlog(n))

class Solution {
public:
    
    int ng(int g){
        if(g<=1){
            return 0;
        }
        return ((g / 2) + (g % 2));
        // return ceil(g/2);
    }
    void merge(vector<int>&a, int m, vector<int>& b, int n) {
        if(n==0){
            return;
        }
        int i,j,g=m+n;
        for(g=ng(g);g>0;g=ng(g)){
            for(i=0;i+g<m;i++){
                if(a[i]>a[i+g]){
                    swap(a[i],a[i+g]);
                }
            }
            
            for (j = g > m ? g - m : 0;i < m && j < n;i++, j++)
                if (a[i] > b[j])
                    swap(a[i], b[j]);
            if(j<n){
                for(j=0;j+g<n;j++){
                    if(b[j]>b[j+g]){
                        swap(b[j],b[j+g]);
                    }
                }
            }
        }
        for(int j=m;j<n+m;j++){
            a[j]=b[j-m];    
        }
    }
};









//Sorting 2nd array
//O(log(n)*n)

class Solution {
public:
    void merge(vector<int>&a, int m, vector<int>& b, int n) {
        if(n==0){
            return;
        }
        
        int i=0;
        while(i<m){
            if(a[i]<=b[0]){
                i++;
            }
            else{
                swap(a[i],b[0]);
                sort(b.begin(),b.end());
            }
 
        }
        for(int j=m;j<n+m;j++){
            a[j]=b[j-m];    
        }
    }
};



