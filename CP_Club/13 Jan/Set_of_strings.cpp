#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> mp;
    for(auto i: s)mp[i]++;
    if(mp.size()<n){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        vector<int> vis(26,0);
        for(int i=0;i<s.size()-1;i++){
            cout<<s[i];
            vis[s[i]-'a']=1;
            if(!vis[s[i+1]-'a'] && n>1){cout<<endl;n--;}
        }
        cout<<s.back();
    }
    return 0;
}