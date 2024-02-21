#include<bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int time,int n,vector<int> arr){
    arr[n-1]+=(1ll<<time)-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1])return false;
        int diff = arr[i+1]-arr[i];
        arr[i] = min(arr[i+1],arr[i]+(1ll<<time)-1);
    }
    return true;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &i: arr)cin>>i;
        int low = 0, high = 50;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(ok(mid,n,arr)){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        cout<<low<<endl;
    }
    return 0;
}