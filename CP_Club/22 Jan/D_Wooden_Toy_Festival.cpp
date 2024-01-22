#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &i: arr)cin>>i;
        sort(arr.begin(),arr.end());
        auto ok = [&](int time){
            int cnt = 0 , mx = arr[0] + time;
            for(auto i: arr){
                if(abs(i-mx)>time){
                    cnt++;
                    mx = i+time;
                }
            }
            return cnt<=2;
        };
        int low = 0, high = 1e9;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(ok(mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        cout<<low<<endl;
    }
    return 0;
}