class Solution {
public:
int dp[10004];
    int f(int i,vector<int>& nums){
        if(i==nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=1e5;
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                ans=min(ans,1+f(i+j,nums));
            }
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
    }
};