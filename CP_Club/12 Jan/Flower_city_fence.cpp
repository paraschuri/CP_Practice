#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool check=true;
        for(int i=0;i<n;i++){
            int num=i+1;
            int low=0,high=n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[mid]>=num){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(high+1!=arr[i]){
                check=false;
            }
        }
        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}