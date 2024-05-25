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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nn = 0, ss = 0, ww = 0, ee = 0;
    for (int i = 0; i < n; i++){
        if(s[i]=='N'){
            nn++;
        }
        if(s[i]=='E'){
            ee++;
        }if(s[i]=='W'){
            ww++;
        }if(s[i]=='S'){
            ss++;
        }
    }

    int _n = nn - (min(nn, ss));
    int _s = ss - (min(nn, ss));
    int _w = ww - min(ww, ee);
    int _e = ee - min(ww, ee);
    if((_n+_s+_w+_e)&1){
        cout << "NO" << endl;
        return;
    }

     _n = (min(nn, ss));
     _s = (min(nn, ss));
     _w =  min(ww, ee);
     _e =  min(ww, ee);

    vector<char> ans(n, 'a');

    for (int i = 0; i < n; i++){
        if(s[i]=='N' and _n>0){
            ans[i] = 'R';
            _n--;
            s[i] = 'a';
        }
        else if(s[i]=='S' and _s>0){
            ans[i] = 'R';
            _s--;
            s[i] = 'a';
        }else if(s[i]=='E' and _e>0){
            ans[i] = 'H';
            _e--;
            s[i] = 'a';
        }else if(s[i]=='W' and _w>0){
            ans[i] = 'H';
            _w--;
            s[i] = 'a';
        }
    }

    int prevN = 0, prevW = 1;
    for (int i = 0; i < n; i++){
        if(s[i]=='N' or s[i]=='S'){
            if(prevN==0){
                ans[i] = 'R';
                prevN = 1;
            }else{
                ans[i] = 'H';
                prevN = 0;
            }
        }else if(s[i]=='W' or s[i]=='E'){
            if(prevW==0){
                ans[i] = 'R';
                prevW = 1;
            }else{
                ans[i] = 'H';
                prevW = 0;
            }
        }
    }

    for(auto x : ans){
        cout << x;
    }
    cout << endl;
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}