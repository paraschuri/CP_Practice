#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main()
{
    int n;
    cin>>n;
    vector<ld> arr(n+1); 
    for(int i=1;i<=n;i++)cin>>arr[i];
    //dp[i][j] be the probability of getting j heads
    //sum of dp[n-1][j] for j>(n+1)/2 will be the final subproblem
    //Base case dp[0][0] = 1;
    //dp[i][j]=dp[i-1][j-1]*arr[i]+dp[i-1][j]*(1-arr[i])
    vector<vector<ld>> dp(n+1,vector<ld>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]*(1-arr[i]);
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j-1]*arr[i]+dp[i-1][j]*(1-arr[i]);
        }
    }
    ld ans=0;
    for(int i=(n+1)/2;i<=n;i++)ans+=dp[n][i];
    cout<<fixed<<setprecision(9)<<ans<<endl;
    return 0;
}