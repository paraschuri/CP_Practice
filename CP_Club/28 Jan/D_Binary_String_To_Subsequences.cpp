#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    queue<int> q1,q2;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(q1.empty()){
               cnt++;
               ans[i]=cnt;
               q2.push(cnt);
            }
            else{
                ans[i]=q1.front();
                q1.pop();
                q2.push(ans[i]);
            }
        }
        else{
            if(q2.empty()){
               cnt++;
               ans[i]=cnt;
               q1.push(cnt);
            }
            else{
                ans[i]=q2.front();
                q2.pop();
                q1.push(ans[i]);
            }
        }
    }
    cout<<cnt<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}