#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> st;
    for(auto i: s){
        if(!st.empty() && st.top()==i){
            st.pop();
        }
        else{
            st.push(i);
        }
    }
    if(st.size()<=1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
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