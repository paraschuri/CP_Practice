#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(auto &i: arr)cin>>i;
        sort(begin(arr),end(arr));
        vector<int> cnt(n);
        for(int i=0;i<n-2;i++){
            cnt[i] = (n-i-1)*(n-i-2)/2;
            // cout<<cnt[i]<<" ";
        }
        // cout<<endl;
        while(!cnt.back())cnt.pop_back();
        for(int i = 1;i<cnt.size();i++)cnt[i]+=cnt[i-1];
        while(q--){
            int x;
            cin>>x;
            int low = 0 , high = cnt.size()-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(cnt[mid]>=x){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            cout<<arr[low]<<endl;
        }
    }
    return 0;
}