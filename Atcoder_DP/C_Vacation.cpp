#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    // dp[i][j] be the maximum possible points of happiness gained till ith index by performing jth task
    vector<vector<int>> dp(n,vector<int>(3,0));
    for(int i=0;i<3;i++)dp[0][i]=arr[0][i];
    for(int i=1;i<n;i++){
        dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=arr[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
    return 0;
}