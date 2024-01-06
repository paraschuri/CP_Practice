#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(auto &i: arr){
            cin>>i;
        }
        int mn=arr[0]-k,mx=arr[0]+k,ans=0;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-mx)>k && abs(arr[i]-mn)>k){
                ans++;
                mn=arr[i]-k;
                mx=arr[i]+k;
            }
            else{   
                mx=min(mx,arr[i]+k);
                mn=max(mn,arr[i]-k);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}