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

vector<int> GCD(int a, int b){
    if(b==0)
        return {1, 0, a};

    vector<int> res = GCD(b, a % b);
    int x = res[0];
    int y = res[1];
    int gcd = res[2];

    int X = y;
    int Y = x - ((a / b) * y);
    return {X, Y, gcd};
}

void solution()
{
    int a, b, c;
    cin >> a >> b >> c;
    int gcd = __gcd(a, b);
    vector<int> res = GCD(a, b);
    
    if(c%gcd==0)
    {
        int k = c / gcd;
        res[0] *= k;
        res[1] *= k;
        cout << res[0] << " " << res[1] << endl;
        if(res[0]>=0 and res[1]>=0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else
        cout << "No" << endl;
}

int main()
{
    Sezar;
    // tc(t) solution();
    solution();
}