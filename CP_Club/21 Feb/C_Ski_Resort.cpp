#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        vector<int> arr(n);
        for(auto &i: arr)cin>>i;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(arr[j]<=q){
                j++;
            }
            else{
                int diff = j-i-k+1;
                if(diff>=0){
                    ans+=diff*(diff+1)/2;
                }
                j++;
                i=j;
            }
        }
        int diff = j-i-k+1;
        if(diff>=0){
            ans+=diff*(diff+1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}