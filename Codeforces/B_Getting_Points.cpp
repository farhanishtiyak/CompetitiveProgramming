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
   ll n,p,l,t;
   cin >> n >> p >> l >> t;
   ll tt = (n + 6) / 7;
   ll day1 = tt / 2;
   ll day2 = tt % 2;
   ll x = (day1 * 2 * t) + (day1 * l);
   ll y = (day2 * t) + (day2 * l);
   ll ans = 0;
   if(p<=x){
       //cout << "if:  ";
       ll perDay = (2 * t) + l;
       ans += (p + perDay - 1) / perDay;
   }
   else{
       //cout << "Else:  ";
       ans += day1;
       p -= x;
       ans += day2;
       p -= y;
       if(p>0){
        ans += (p + l - 1) / l;
       }
       //cout << ans << endl;
   }

   ans = n - ans;
   cout << ans << endl;
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}