#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    //dp[i][j] be the edit distance till ith index of string a & jth index of string b
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int i=0;i<=m;i++)dp[0][i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+dp[i-1][j-1];
            }
            dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i][j-1])+1);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}