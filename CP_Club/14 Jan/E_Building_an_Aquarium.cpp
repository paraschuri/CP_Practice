#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define maxn 100000000000017    
#define endl "\n"
#define mk make_pair
#define pll pair<ll, ll>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
 
typedef long long ll;
typedef long double ld;

bool isValid(ll mid,ll h,vector<int>& arr){
    
    for(auto i: arr){
        if(i<=mid){
            h-=mid-i;
        }
    }
    return h>=0;
}

void solve(){
    int n,h;
    cin>>n>>h;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    ll low=0,high=1e10;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(isValid(mid,h,arr)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<high<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}