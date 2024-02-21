#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> leafs;

int f(int node,int parent,vector<int> adj[]){
    int cnt=0;
    for(auto i: adj[node]){
        if(i!=parent){
            cnt+=f(i,node,adj);
        }
    }
    if(!cnt)cnt++;
    return leafs[node]=cnt;
}

void solve(){
    int n;
    cin>>n;
    leafs.resize(n+1,0);
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    f(1,-1,adj);
    // for(auto i: leafs)cout<<i<<" ";
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<leafs[a]*leafs[b]<<endl;
    }
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