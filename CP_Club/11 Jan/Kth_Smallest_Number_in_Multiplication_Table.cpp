class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;
        while(low<=high){
            int mid = low + (high-low)/2;
            int curr=0,smol=0;
            for(int i=1;i<=m && i<=mid;i++){
                if(mid%i==0 && mid<=i*n)curr++;
                smol+=min(n,(mid-1)/i);
            }
            if(k>smol && k<=smol+curr){
                return mid;
            }
            else if(k<=smol){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return 0;
    }
};