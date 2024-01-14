class Solution {
public:
    int dp[10002][101];
    int solve(int i,int k){
        if(i==0 || i==1)return 1;
        if(k==1)return i;
        if(dp[i][k]!=-1)return dp[i][k];
        int low=1,high=i;
        int ans=1e6;
        while(low<=high){
            int mid = low+(high-low)/2;
            int down = solve(mid-1,k-1);
            int up = solve(i-mid,k);
            ans=min(ans,1+max(up,down));
            if(down<up){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return dp[i][k]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};