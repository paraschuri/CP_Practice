#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

void solve(){
    int n;
    cin>>n;
    ordered_set st;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(begin(arr),end(arr));
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        ans += st.order_of_key(arr[i].second);
        st.insert(arr[i].second);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}