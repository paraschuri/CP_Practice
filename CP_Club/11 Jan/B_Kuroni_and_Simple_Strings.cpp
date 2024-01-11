#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int> suff(n+1,0);
    for(int i=n-1;i>=0;i--){
        suff[i]=suff[i+1]+(s[i]==')');
    }
    int cnt=0,ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(' && cnt<suff[i]){
            cnt++;
        }
    }
    if(cnt==0){
        cout<<0<<endl;
        exit(0);
    }
    cout<<1<<endl<<2*cnt<<endl;
    int temp=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(' && temp<cnt){
            cout<<i+1<<" ";
            temp++;
        }
        if(s[i]==')' && suff[i]<=cnt){
            cout<<i+1<<" ";
            ans--;
        }
    }
    return 0;
}