#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> arr;
int cnt;
void merge(int l,int m,int h){
    if(arr[l]>arr[h]){
        cnt++;
        int i=l,j=m+1;
        while(j<=h){
            swap(arr[i++],arr[j++]);
        }
    }
}

void f(int l,int h){
    if(l>=h)return;
    int mid=l+(h-l)/2;
    f(l,mid);
    f(mid+1,h);
    merge(l,mid,h);
}

void solve(){
    int n;
    cin>>n;
    cnt=0;
    arr.resize(n);
    for(auto &i: arr)cin>>i;
    f(0,n-1);
    if(!is_sorted(arr.begin(),arr.end())){
        cout<<-1<<endl;
    }
    else{
        cout<<cnt<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}