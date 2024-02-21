#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    multiset<char> mst;
    for(auto i:s)mst.insert(i);
    stack<char> st;
    string ans="";
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
        auto it=mst.find(s[i]);
        mst.erase(it);
        while(!mst.empty() && !st.empty() && st.top()<=*mst.begin()){
            ans+=st.top();
            st.pop();
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}