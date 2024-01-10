#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(auto &i: grid)cin>>i;
    vector<vector<int>> dp(n,vector<int>(m,0));
    int mod = 1e9+7;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            if(i>0 && grid[i][j]=='.'){
                dp[i][j]=dp[i-1][j];
            }
            if(j>0 && grid[i][j]=='.'){
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}