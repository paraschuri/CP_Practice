#include<bits/stdc++.h>
using namespace std;
#define int long long

int dfs(int node,vector<int> adj[],vector<int>& ans, vector<int>& check){
    int ok = check[node];
    for(auto i: adj[node]){
        ok &= dfs(i,adj,ans,check);
    }
    if(ok)ans.push_back(node);
    return check[node];
}

int32_t main()
{
    int n;
    cin>>n;
    vector<int> adj[n+1],check(n+1);
    int root;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        if(u==-1){
            root=i;
        }
        else{
            adj[u].push_back(i);
            check[i]=v;
        }
    }
    vector<int> ans;
    dfs(root,adj,ans,check);
    if(ans.size()==0){
        cout<<-1<<endl;
    }
    else{
        sort(ans.begin(),ans.end());
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}