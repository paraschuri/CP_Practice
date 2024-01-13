#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=min({a,b,c});
        a-=ans,b-=ans,c-=ans;
        ans+=min({a,b,(a+b)/3});
        cout<<ans<<endl;
    }
    return 0;
}