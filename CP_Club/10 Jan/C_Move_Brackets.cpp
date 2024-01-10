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
        int cnt1=0,ans=0;
        for(auto i: s){
            if(i==')'){
                if(cnt1)cnt1--;
                else ans++;
            }
            else{
                cnt1++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}