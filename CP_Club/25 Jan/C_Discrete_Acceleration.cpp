#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve(){
    int n,l;
    cin>>n>>l;
    vector<int> arr(n);
    for(auto &i: arr)cin>>i;
    auto ok=[&](double x){
        double a=0,b=l;
        double t=x,s=1;
        for(auto i: arr){
            if((i-a)/s<=t){
                t-=(i-a)/s;
                s++;
                a=i;
            }
            else{
                break;
            }
        }
        a+=s*t;
        t=x,s=1;
        for(int i=n-1;i>=0;i--){
            if((b-arr[i])/s<=t){
                t-=(b-arr[i])/s;
                s++;
                b=arr[i];
            }
            else{
                break;
            }
        }
        b-=s*t;
        return a>=b;
    };
    double low=0, high=1e10;
    while(high-low>1e-6){
        double mid = low+(high-low)/2;
        if(ok(mid)){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<low<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}