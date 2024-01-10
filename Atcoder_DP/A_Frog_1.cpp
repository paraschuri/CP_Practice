#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)cin>>i;
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=abs(arr[i]-arr[i-1])+dp[i-1];
        if(i>1)dp[i]=min(dp[i],abs(arr[i]-arr[i-2])+dp[i-2]);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}