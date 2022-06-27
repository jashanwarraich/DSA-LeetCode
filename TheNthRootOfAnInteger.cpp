// Q61 https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Newton Raphson Method
// Time Complexity : O(log(M) * log(N))
// Space Complexity : O(1),


double findNthRootOfM(int n, long long m) {

    // Variable to store maximum possible error in order
    // to obtain the precision of 10^(-6) in the answer.
    double error = 1e-7;

    // Difference between the current answer, and the answer
    // in next iteration, which we take as big as possible initially.
    double diff = 1e18;

    // Guessed answer value
    double xk = 2;

    // We keep on finding the precise answer till the difference between
    // answer of two consecutive iteration become less than 10^(-7).
    while (diff > error) {

        // Answer value in the next iteration.
        double xk_1 = (pow(xk, n) * (n - 1) + m) / (n * pow(xk, n - 1));

        // Difference of answer in consecutive states updated.
        diff = abs(xk - xk_1);

        // Updating the current answer with the answer of next iteration.
        xk = xk_1;
    }

    // Returning the nthRootOfM with precision upto 6 decimal places
    // which is xk.
    return xk;
}







//USING BINARY SEARCH

// Time: N*log(m*10^d)
// Space: O(1)

long double multi(long double mid,int n){
    long double ans=1.0;
    for(int i=1;i<=n;i++){
        ans*=mid;
    }
    return ans;
}

long double findNthRootOfM(int n, long double m) {
	long double eps=1e-8;
    long double l=1,h=m;
    while(abs(h-l)>eps){
        long double mid=(l+h)/2.0;
        if(multi(mid,n)<m)
            l=mid;
        else
            h=mid;
    }
    return (l+h)/2.0;
    
}





