#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n,h;
        cin>>n>>h;
        vector<int> arr(n);
        for(auto &i: arr)cin>>i;
        auto ok=[&](int mid){
            int cnt=mid;
            for(int i=0;i<n-1;i++){
                cnt+=min(mid,arr[i+1]-arr[i]);
            }
            return cnt>=h;
        };
        int low=1,high=1e18;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(ok(mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<low<<endl;
    }
    return 0;
}