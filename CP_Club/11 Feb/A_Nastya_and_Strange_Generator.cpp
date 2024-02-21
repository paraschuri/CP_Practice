#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        mp[num]=i;
    }
    vector<int> vis(n+1,0);
    vis[n]=1;
    int prev = mp[1];
    vis[mp[1]]=1;
    for(int i=2;i<=n;i++){
        if(vis[prev+1] || prev+1==mp[i]){
            prev=mp[i];
            vis[mp[i]]=1;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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