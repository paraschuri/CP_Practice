#include<bits/stdc++.h>
using namespace std;
#define int long long

int dfs(int node,vector<int> adj[],vector<int>&dp){
    if(dp[node]!=-1)return dp[node];
    int ans=0;
    for(auto i: adj[node]){
        ans = max(ans,1+dfs(i,adj,dp));
    }
    return dp[node]=ans;
}

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> dp(n+1,-1);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dp[i]==-1){
            ans=max(ans,dfs(i,adj,dp));
        }
    }
    cout<<ans<<endl;
    return 0;
}