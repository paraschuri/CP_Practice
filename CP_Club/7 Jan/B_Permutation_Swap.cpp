#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n+1);
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            cnt=__gcd(cnt,abs(arr[i]-i));
        }
        cout<<cnt<<endl;
    }
    return 0;
}