class Solution {
public:
    double solve(double x, long long n){
           
        double ans;
        if(n==0){
            return 1;
        }
        if(x==0){
            return 0;
        }
        if(x==1){
            return 1;
        }
        double multiplier =solve(x,n/2);
        if((n & 1)==0){
            // when n is even 
            ans= multiplier*multiplier;
        }
        if((n & 1) !=0){
            ans=x * multiplier*multiplier;
        }

        return ans;
    }
    double myPow(double x, int n) {
        
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }

        return solve(x,N);
    }
};