#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr)cin>>i;
    bool f1 = 1, f2 = 1;
    for(int i = 0;i<n-1;i++){
        if(abs(arr[i]-arr[i+1])%2 && (i+1)%2){
            f1=0;
            break;
        }
    }
    for(int i = n-2;i>=0;i--){
        if(abs(arr[i]-arr[i+1])%2 && (n-i-1)%2){
            f2=0;
            break;
        }
    }
    cout<<((f1 || f2)?"YES":"NO")<<endl;
    return 0;
}