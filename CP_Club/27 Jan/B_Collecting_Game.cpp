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
        vector<int> temp=arr;
        sort(begin(temp),end(temp));
        vector<int> temp2(n);
        temp2[0]=temp[0];
        for(int i=1;i<n;i++)temp2[i]=temp2[i-1]+temp[i];
        map<int,int> mp;
        mp[temp.back()]=n-1;
        int cnt=n-1;
        for(int i=n-2;i>=0;i--){
            if(temp2[i]>=temp[i+1]){
                mp[temp[i]]=cnt;
            }  
            else{
                mp[temp[i]]=i;
                cnt=i;
            }
        }
        for(auto i: arr){
            cout<<mp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}