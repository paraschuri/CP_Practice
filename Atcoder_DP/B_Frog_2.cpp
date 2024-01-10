#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i: arr)cin>>i;
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i>=j){
                dp[i]=min(dp[i],abs(arr[i]-arr[i-j])+dp[i-j]);
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}