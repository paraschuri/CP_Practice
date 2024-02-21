#include<bits/stdc++.h>
using namespace std;
#define int long long

int cnt;
 
void dfs(int node,int parent,vi adj[]){
    int temp=0;
    for(auto i: adj[node]){
        if(i!=parent){
            temp++;
            dfs(i,node,adj);
        }
    }
    cnt+=max(0ll,temp-1);
}
 
void solve()
{
    int n;
    cin>>n;
    cnt=0;
    vi adj[n+1],deg(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int root=find(deg.begin(),deg.end(),1)-deg.begin();
    dfs(root,-1,adj);
    cout<<1+(cnt+1)/2<<endl;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}