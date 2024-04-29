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


void solution()
{
    ll n;
    cin >> n;
    ll arr[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    ll r[n + 1];
    for (int i = 1; i<=n; i++){
        if(i==1){
            r[i] = 1;
        }else if(i==n){
            r[i] = 0;
        }else{
            ll f = arr[i + 1] - arr[i];
            ll b = arr[i] - arr[i - 1];
            if(f<b){
                r[i] = 1;
            }else{
                r[i] = f;
            }
        }
    }

    ll l[n + 1];
    for (int i = 1; i<=n; i++){
        if(i==1){
            l[i] = 0;
        }else if(i==n){
            l[i] = 1;
        }else{
            ll f = arr[i + 1] - arr[i];
            ll b = arr[i] - arr[i - 1];
            if(b<f){
                l[i] = 1;
            }else{
                l[i] = b;
            }
        }
    }

    ll rs[n + 1];
    ll ls[n + 1];
    rs[0] = 0;
    ls[0] = 0;
    for (int i = 1; i <= n; i++){
        rs[i] = rs[i - 1] + r[i];
        ls[i] = ls[i - 1] + l[i];
    }

    ll q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a<b){
            a--;
            b--;
            ll ans = rs[b] - rs[a];
            cout << ans << endl;
        }else{
            ll ans = ls[a] - ls[b];
            cout << ans << endl;
        }
    }
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}