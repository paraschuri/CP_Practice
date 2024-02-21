class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0)return 1.0;
        if(n<0){
            return 1/myPow(x,-n);
        }
        double ans = myPow(x,n/2);
        ans*=ans;
        if(n%2){
            ans*=x;
        }
        return ans;
    }
};