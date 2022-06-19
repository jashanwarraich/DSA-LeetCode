//https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
// C++ program to Find the repeating
// and missing elements
 
#include <bits/stdc++.h>
using namespace std;
 
/* The output of this function is stored at
*x and *y */
void getTwoElements(int arr[], int n,
                    int* x, int* y)
{
    /* Will hold xor of all elements
    and numbers from 1 to n */
    int xor1;
 
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    /* XOR the previous result with numbers
    from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
 
    /* Now divide elements into two
    sets by comparing a rightmost set
    bit of xor1 with the bit at the same
    position in each element. Also,
    get XORs of two sets. The two
    XORs are the output elements.
    The following two for loops
    serve the purpose */
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;
 
        else
            /* i belongs to second set*/
            *y = *y ^ i;
    }
 
    /* *x and *y hold the desired
        output elements */
}
 
/* Driver code */
int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);
 
    getTwoElements(arr, n, x, y);
    cout << " The missing element is " << *x << " and the repeating"
         << " number is " << *y;
    getchar();
}
 
// This code is contributed by Code_Mech




//space: O(n)
// Time O(n)
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
    // Write your code here 
    vector <int> b(n+1);
    pair<int,int> p;
    for(int i=0;i<n+1;i++){
        b[i]=0;
    }
    for(int i=0;i<n;i++){
        b[a[i]]++;
    }
    for(int j=1;j<n+1;j++){
        if(b[j]==0){
            p.first=j;
        }
         if(b[j]==2){
            p.second=j;
        }
        
    }
    return p;
    
    
}


// Space: O(1)
// Time: O(nlog(n))
// No extra space used but changed the original array

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
    pair<int,int> p;

    sort(a.begin(),a.end());
    int rs=(n*(n+1))/2;
    int s=0;
    int i;
    for(i=0;i<n-1;i++){
        s+=a[i];
        if(a[i]==a[i+1]){
            p.second=a[i];
        }       
    }
    s+=a[i];
//     cout<<s<<" ";
//     cout<<rs<<" ";
    p.first=rs-(s-p.second);
    return p;
}
