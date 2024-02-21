#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int l,r,m;
    cin>>l>>r>>m;
    for(int i=l;i<=r;i++){
        if(i>m){
            if(r-l>=i-m){
                cout<<i<<" "<<l<<" "<<l+i-m<<endl;
                return;
            }
        }
        else if(m%i==0){
            cout<<i<<" "<<l<<" "<<l<<endl;
            return;
        }
        else{
            int temp = m/i;
            int num1 = temp*i, num2 = i*(temp+1);
            if(r-l>=m-num1){
                cout<<i<<" "<<l+m-num1<<" "<<l<<endl;
                return;
            }
            if(r-l>=num2-m){
                cout<<i<<" "<<l<<" "<<l+num2-m<<endl;
                return;
            }
        }
    }
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