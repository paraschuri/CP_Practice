#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        bool f=0;
        for(auto &i: arr){
            cin>>i;
            if(i%k==0){
                f=1;
            }
        }
        if(f){
            cout<<0<<endl;
            continue;
        }
        if(k==4){
            int two=0,cmp=INT_MAX;
            for(auto i: arr){
                if(i%2==0){
                    two++;
                }
                cmp=min(cmp,k-(i%k));
            }
            if(two>=2){
                cout<<0<<endl;
            }
            else if(cmp==1 || two==1){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
        else{
            int cmp=INT_MAX;
            for(auto i: arr){
                cmp=min(cmp,k-(i%k));
            }
            cout<<cmp<<endl;
        }
    }
}