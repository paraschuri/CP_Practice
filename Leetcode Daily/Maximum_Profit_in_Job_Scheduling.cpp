class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<int> dp(n+1,0);
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({{endTime[i],startTime[i]},profit[i]});
        }
        sort(v.begin(),v.end());
        dp[0]=v[0].second;
        int ok=0;
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            int low=0,high=i-1,ans=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(v[mid].first.first<=v[i].first.second){
                    low=mid+1;
                    ans=mid;
                }
                else{
                    high=mid-1;
                }
            }
            if(ans==-1){
                dp[i]=max(dp[i],v[i].second);
            }
            else{
                dp[i]=max(dp[i],dp[ans]+v[i].second);
            }
            ok=max(ok,dp[i]);
        }
        return ok;
    }
};