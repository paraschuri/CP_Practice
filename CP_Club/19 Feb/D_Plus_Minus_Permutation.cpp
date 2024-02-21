#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        ll a=n/x,b=n/y;
        ll cmp=lcm(x,y);
        cmp=n/cmp;
        ll l=n-a+cmp;
        ll ans=(n*(n+1)/2)-(l*(l+1)/2);
        b-=cmp;
        ans-=b*(b+1)/2;
        cout<<ans<<endl;
    }
    return 0;
}