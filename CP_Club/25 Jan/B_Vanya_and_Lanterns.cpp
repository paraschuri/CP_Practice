#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i: arr)cin>>i;
    sort(arr.begin(),arr.end());
    double ans = 0;
    for(int i = 0;i<n-1;i++){
        ans = max(ans,(arr[i+1]-arr[i])/2.0);
    }
    ans = max({ans,arr[0]*1.0,(k-arr.back())*1.0});
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}