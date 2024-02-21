#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        adj[u].push_back(i);
    }
    bool ok=1;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(auto j: adj[i]){
            cnt += (adj[j].size()==0);
        }
        ok &= (cnt>=3 || (adj[i].size()==0));
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}