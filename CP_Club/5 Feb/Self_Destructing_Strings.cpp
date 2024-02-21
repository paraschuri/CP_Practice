#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n= s.size();
        int cnt1=0;
        for(auto i: s){
            if(i=='1')cnt1++;
        }
        if(n%2 || cnt1==0 || cnt1==n){
            cout<<-1<<endl;
        }
        else{
            cout<<abs(2*cnt1-n)/2<<endl;
        }
    }
    return 0;
}