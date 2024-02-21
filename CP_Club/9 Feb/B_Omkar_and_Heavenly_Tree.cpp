#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        set<int> st;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            st.insert(b);
        }
        int node=1;
        for(auto it: st){
            if(it!=node)break;
            node++;
        }
        for(int i=1;i<=n;i++){
            if(i!=node){
                cout<<i<<" "<<node<<endl;
            }
        }
    }
    return 0;
}