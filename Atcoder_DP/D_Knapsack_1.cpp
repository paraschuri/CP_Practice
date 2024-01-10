#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,w;
    cin>>n>>w;
    vector<int> weight(n),value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    //dp[i][j] be the maximum value till ith index by taking j weight
    vector<int> prev(w+1);
    for(int i=1;i<=w;i++)if(i>=weight[0])prev[i]=value[0];
    for(int i=1;i<n;i++){
        vector<int> curr(w+1);
        for(int j=1;j<=w;j++){
            curr[j]=prev[j];
            if(j>=weight[i]){
                curr[j]=max(curr[j],value[i]+prev[j-weight[i]]);
            }
        }
        prev=curr;
    }
    cout<<prev[w]<<endl;
    return 0;
}