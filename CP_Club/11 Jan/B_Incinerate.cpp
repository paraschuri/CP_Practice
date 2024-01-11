#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) begin(v),end(v)
#define ff first
#define ss second

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> arr(n);
    for (auto &i : arr)
    {
        cin >> i.ff;
    }
    for (auto &i : arr)
    {
        cin >> i.ss;
    }
    sort(all(arr));
    vector<int> suff(n, 0);
    suff[n - 1] = arr[n - 1].ss;
    int temp = k;
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = min(suff[i + 1], arr[i].ss);
    }
    for (int i = 0; i < n; i++)
    {
        while (arr[i].ff > k)
        {
            k += temp - suff[i];
            temp -= suff[i];
            if (temp < 0)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}