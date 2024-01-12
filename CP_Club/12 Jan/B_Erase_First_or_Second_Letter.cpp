#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> vis(26,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[s[i]-'a']){
                ans+=(n-i);
                vis[s[i]-'a']=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}