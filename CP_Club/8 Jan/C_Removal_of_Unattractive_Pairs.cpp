#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int> mp;
        int temp=0;
        for(auto i: s){
            mp[i]++;
            temp=max(temp,mp[i]);
        }
        temp = 2*temp - n;
        if(temp<0){
            if(n&1){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            cout<<temp<<endl;
        }
    }
    return 0;
}