#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define maxn 100000000000017
#define endl "\n"
#define INF (int)1e18
#define mk make_pair
#define set_bits __builtin_popcount
#define sz(x) ((int)(x).size())
#define pi pair<int, int>
#define vi vector<int>
#define vpi vector<pi>
#define all(v) v.begin(), v.end()
#define srt(v) sort(all(v))
#define vi vector<int>
#define vld vector<ld>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define pb push_back
#define rep(i, k, n) for (int i = k; i < n; i++)
#define rrep(i,k,n) for (int i=n;i>=k;i--)
#define input(vi) for(auto &i: vi) {cin>>i;}
#define print(vi) for(auto &i: vi) {cout<<i<<" ";} cout<<endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
typedef unsigned long long ull;
typedef long double ld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n,l,r;
    cin>>n>>l>>r;
    vi arr(n);
    input(arr);
    map<int,int> mp1,mp2;
    for(int i=0;i<n;i++){
        if(i<l){
            mp1[arr[i]]++;
        }
        else{
            mp2[arr[i]]++;
        }
    }
    int rem = abs(l-r),ans=0;
    if(l<=r){
        for(auto i:mp1){
            if(mp2[i.ff]){
                int mn=min(i.ss,mp2[i.ff]);
                i.ss-=mn;
                mp2[i.ff]-=mn;
            }
            if(i.ss){
                ans+=i.ss;
            }
        }
        for(auto i: mp2){
            if(rem){
                int mn=min(rem,(i.ss%2?i.ss-1:i.ss));
                ans+=mn/2;
                rem-=mn;
                i.ss-=mn;
            }
        }
        ans+=rem;
    }
    else{
        for(auto i:mp2){
            if(mp1[i.ff]){
                int mn=min(mp1[i.ff],mp2[i.ff]);
                mp1[i.ff]-=mn;
                i.ss-=mn;
            }
            if(i.ss){
                ans+=i.ss;
            }
        }
        for(auto i: mp1){
            if(rem){
                int mn=min(rem,(i.ss%2?i.ss-1:i.ss));
                ans+=mn/2;
                rem-=mn;
                i.ss-=mn;
            }
        }
        ans+=rem;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
