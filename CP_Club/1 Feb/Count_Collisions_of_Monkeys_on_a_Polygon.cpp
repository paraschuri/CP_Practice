class Solution {
public:
    long long binExp(long long a, long long b, int M){
        long long ans = 1;
        while(b>0){
            if(b&1) ans = (ans*a) % M;
            a=(a*a)%M;
            b>>=1;
        }
        return ans;
    }
    int monkeyMove(int n) {
        int mod=1e9+7;
        return int(binExp(2,n,mod)+mod-2)%mod;
    }
};