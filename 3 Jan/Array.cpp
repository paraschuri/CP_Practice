#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],neg=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        neg+=(a[i]<0);
    }
    sort(a,a+n);
    cout<<"1 "<<a[0]<<endl;
    bool f=1;
    int i;
    if(neg%2==0){i=2;cout<<n-3<<" ";}
    else{i=1;cout<<n-2<<" ";}
    for(;i<n;i++){
        if(a[i]==0){
            if(!f)cout<<"0 ";
            else f=0;
        }
        else{
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
    if(neg%2==0){
        cout<<"2 0 "<<a[1]<<endl;
    }
    else{
        cout<<"1 0"<<endl;
    }
    return 0;
}