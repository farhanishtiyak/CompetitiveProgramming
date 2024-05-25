#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define  tc(t)  int t; cin >> t; while (t--)
#define  ll     long long

typedef  vector<int> vi;
typedef  vector<ll> vll;
typedef  pair<int, int> pii;
typedef  pair<ll, ll> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

#define    all(v)         (v).begin(),(v).end()
#define    all1(v)        (v).begin()+1,(v).end()
#define    sort0(v)       sort(all(v))
#define    pb             emplace_back
#define    ppb            pop_back
#define    mkp            make_pair

#define    for0(i,n)      for (int i = 0; i < n; i++)
#define    forr(i,a,b)    for(i=a;i<=b;i++)

#define    yes            cout << "YES" << endl;
#define    no             cout << "NO" << endl;
#define    endl           "\n"
#define    infinity       9999999999999
const      ll mod = 998244353;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a ) % mod; b >>= 1;} return res;}

ll n, x;
vll c, h;

ll findMax(int i, ll hs, ll s, vector<vll>& dp, vector<vll>& sp){
    
    if(i==n){
        return 0;
    } 
    
    if(dp[i][hs]!=-1 && sp[i][hs]>=s) return dp[i][hs];
    
    ll not_take, take=0;
    
    not_take = findMax(i+1, hs, s+x, dp, sp);
    
    if(s>=c[i]) take = findMax(i+1, hs+h[i], s-c[i]+x, dp, sp) + h[i];
    
    sp[i][hs] = s;
    
    return dp[i][hs] = max(not_take, take);
    
}

void solution()
{
    ll sum = 0;
    cin >> n >> x;
    c.clear();
    h.clear();

    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        c.pb(a);
        h.pb(b);
        sum += b;
    }

    vector<vll> sp(n, vll(sum + 1));
    vector<vll> dp(n, vll(sum + 1, -1));

    ll ans = findMax(0, 0, 0,  dp, sp);
    cout<<ans<<"\n";
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}