#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    // dp[i][j] be the length of longest common subsequence till ith index of string s and jth index of string t
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i-1]==t[j-1])dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
        }
    }
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(begin(ans),end(ans));
    cout<<ans<<endl;    
    return 0;
}