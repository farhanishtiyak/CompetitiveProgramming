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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char, int> m;
    for (int i = 0; i < s.size(); i++) m[s[i]]++;
    vector<int> even, odd;
    for(auto it: m){
        if(it.second & 1) odd.pb(it.second);
        else even.pb(it.second);
    }
    int cnt = 0;
    for(auto it: odd){
        if(cnt<k) {
            cnt++;
            it--;
        }
    }
    for(auto it: odd){
        if(it&1) {
           continue;
        }
        else{
            even.pb(it);
            it = 0;
        }
    }

    int len = n-k;
    int ff = 0;
    if(len&1){
        for(auto it: odd){
            if(it&1 and ff ==0){
                ff = 1;
                even.pb(it-1);
                len--;
            }
        }
    }

    for(auto it: odd){
        if(it&1 and cnt<k) {
            cnt++;
            even.pb(it-1);
        }
    }

    for(auto it : even){
        if(cnt<k){
            cnt+=(min(it, (k-cnt)));
            it-=(min(it,(k-cnt)));
        }
    }

    int oo = 0;
    for(auto it: even){
        if(it&1) oo++;
    }
    if(oo) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}