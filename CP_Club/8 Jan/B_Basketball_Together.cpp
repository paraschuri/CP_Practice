#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    vector<int> arr(n);
    for(auto &i: arr)cin>>i;
    sort(arr.rbegin(),arr.rend());
    int j=n-1,ans=0;
    for(int i=0;i<n;i++){
        int cmp=d/arr[i]+1;
        if(j-i+1>=cmp){
            ans++;
            j-=cmp-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}