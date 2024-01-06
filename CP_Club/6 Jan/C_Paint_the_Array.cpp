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
        int f=0,s=0;
        for(int i=0;i<n;i++){
            if(i&1){
                s=__gcd(s,arr[i]);
            }
            else{
                f=__gcd(f,arr[i]);
            }
        }
        bool a=1,b=1;
        for(int i=0;i<n;i++){
            if(i&1){
                if(arr[i]%f==0)a=0;
            }
            else{
                if(arr[i]%s==0)b=0;
            }
        }
        if(a){
            cout<<f<<endl;
        }
        else if(b){
            cout<<s<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}