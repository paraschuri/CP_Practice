#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)cin>>i;
    sort(arr.begin(),arr.end());
    int ans = 1, sum =arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=sum){
            sum += arr[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
