#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> arr;

void solve(int l,int r,int n,int cnt,vector<int>& ans){
    if(l>r)return;
    if(l==r){
        ans[l]=cnt;
        return;
    }
    int ind=l;
    for(int i=l;i<=r;i++){
        if(arr[i]>arr[ind])ind=i;
    }
    ans[ind]=cnt;
    solve(l,ind-1,n,cnt+1,ans);
    solve(ind+1,r,n,cnt+1,ans);
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        arr.resize(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];
        vector<int> ans(n+1);
        solve(1,n,n,0,ans);
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}