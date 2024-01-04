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
        for(auto &i: arr)cin>>i;
        int i=0;
        while(i<n){
            if(arr[i]<i)break;
            i++;
        }
        int j=n-1;
        while(j>=0){
            if(arr[j]<n-j-1)break;
            j--;
        }
        cout<<(i>=j+2?"YES":"NO")<<endl;
    }
    return 0;
}


