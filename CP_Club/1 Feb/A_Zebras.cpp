#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    queue<int> q1,q2;
    vector<vector<int>> ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(q2.empty()){
                ans.push_back({i+1});
                q1.push(ans.size()-1);
            }
            else{
                int ind =q2.front();
                q2.pop();
                ans[ind].push_back(i+1);
                q1.push(ind);
            }
        }
        else{
            if(q1.empty()){
                cout<<-1<<endl;
                return;
            }
            else{
                int ind =q1.front();
                q1.pop();
                ans[ind].push_back(i+1);
                q2.push(ind);
            }
        }
    }
    if(!q2.empty()){
        cout<<-1<<endl;
        return;
    }
    
    cout<<ans.size()<<endl;
    for(auto i: ans){
        cout<<i.size()<<" ";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}