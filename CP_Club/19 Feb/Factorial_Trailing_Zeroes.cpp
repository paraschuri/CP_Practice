class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0,num=5;
        while(num<=n){
            ans+=n/num;
            num*=5;
        }
        return ans;
    }
};