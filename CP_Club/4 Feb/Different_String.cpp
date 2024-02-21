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
        string ans="";
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            if(temp[i]=='0'){
                ans+='1';
            }
            else{
                ans+='0';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}