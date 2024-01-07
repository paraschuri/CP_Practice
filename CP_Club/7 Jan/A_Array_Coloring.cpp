#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        int cnt=0;
        for(auto &i: arr){
            cin>>i;
            cnt+=(i%2);
        }
        cout<<(cnt%2==0?"YES":"NO")<<endl;
    }
    return 0;
}