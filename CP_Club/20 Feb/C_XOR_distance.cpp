#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define endl "\n"
#define INF (int)1e18
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define msb(x) (63-__builtin_clzll(x))
#define pi pair<int, int>
#define vi vector<int>
#define vpi vector<pi>
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define pb push_back
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
int getSqrt(int x) {int lo = 0, hi = 1e9, c = 0;while(lo <= hi) {int mid = (lo + hi) / 2;if((mid * mid) <= x) {c = mid;lo = mid + 1;} else hi = mid - 1;}return c;}
/*--------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x = 0;
    for(int i=61;i>=0;i--){
        if((1ll<<i)&c){
            x=i;
            break;
        }
    }
    if(a<b)swap(a,b);
    int l=0,m=0;
    for(int i=61;i>x;i--){
        if((1ll<<i)&a){
            l |= (1ll<<i);
        }
        if((1ll<<i)&b){
            m |= (1ll<<i);
        }
    }
    int cnt=0;
    for(int i=x;i>=0;i--){
        if(((1ll<<i)&a) && ((1ll<<i)&b)){
            l |= (1ll<<i);
            m |= (1ll<<i);
        }
        else if(((1ll<<i)&a) && !((1ll<<i)&b)){
            if(l>m && cnt+(1ll<<i)<=c){
                m |= (1ll<<i);
                cnt |= (1ll<<i);
            }
            else{
                l |= (1ll<<i);
            }
        }
        else if(!((1ll<<i)&a) && ((1ll<<i)&b)){
            if(l<m && cnt+(1ll<<i)<=c){
                l |= (1ll<<i);
                cnt |= (1ll<<i);
            }
            else{
                m |= (1ll<<i);
            }
        }
    }
    cout<<abs(l-m)<<endl;
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