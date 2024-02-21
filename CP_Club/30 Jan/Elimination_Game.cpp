class Solution {
public:
    int lastRemaining(int n) {
        int start = 1,dir=0,curr=1;
        while(n>1){
            if(n%2 || dir==0){
                start += curr;
            }
            dir ^= 1;
            n/=2;
            curr*=2;
        }
        return start;
    }
};