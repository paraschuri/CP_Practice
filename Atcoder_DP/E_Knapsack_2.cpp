#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,w;
    cin>>n>>w;
    int sz = 100001;
    vector<int> weight(n),value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    //dp[i][j] is the weight required at ith index to get value j, -1 if not possible
    vector<int> prev(sz,INT_MAX);
    int ans=0;
    for(int i=1;i<sz;i++)if(i<=value[0])prev[i]=weight[0];
    for(int i=1;i<n;i++){
        vector<int> curr(sz);
        for(int j=1;j<sz;j++){
            curr[j]=prev[j];
            if(j<=value[i])curr[j]=min(curr[j],weight[i]);
            if(j>value[i] && prev[j-value[i]]!=INT_MAX && weight[i]+prev[j-value[i]]<=w){
                curr[j]=min(curr[j],weight[i]+prev[j-value[i]]);
            } 
        }
        prev=curr;
    }
    for(int i=1;i<sz;i++)if(prev[i]!=INT_MAX)ans=i;
    cout<<ans<<endl;
    return 0;
}