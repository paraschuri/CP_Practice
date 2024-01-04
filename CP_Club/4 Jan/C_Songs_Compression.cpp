#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long long cmp=0;
    vector<int> diff(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        cmp+=u;
        diff[i]=u-v;
    }
    sort(diff.rbegin(),diff.rend());
    cmp-=min(cmp,m*1ll);
    int ans=0;
    for(auto i: diff){
        if(i<0 || cmp<=0)break;
        cmp-=i;
        ans++;
    }
    if(cmp>0)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}