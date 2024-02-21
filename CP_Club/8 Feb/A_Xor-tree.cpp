#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node,int parent,vector<int> adj[],int level,int cnt1,int cnt2,vector<int>& curr,vector<int>& req,vector<int> &ans){
    if(level%2){
        if(cnt1%2){
            curr[node]^=1;
        }
        if(curr[node]!=req[node]){
            cnt1++;
            ans.push_back(node);
        }
    }
    else{
        if(cnt2%2){
            curr[node]^=1;
        }
        if(curr[node]!=req[node]){
            cnt2++;
            ans.push_back(node);
        }
    }
    for(auto i: adj[node]){
        if(i!=parent){
            dfs(i,node,adj,level+1,cnt1,cnt2,curr,req,ans);
        }
    }
}

int32_t main()
{
    int n;
    cin>>n;
    vector<int> adj[n+1],curr(n+1),req(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>curr[i];
    for(int i=1;i<=n;i++)cin>>req[i];
    vector<int> ans;
    dfs(1,-1,adj,0,0,0,curr,req,ans);
    cout<<ans.size()<<endl;
    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}