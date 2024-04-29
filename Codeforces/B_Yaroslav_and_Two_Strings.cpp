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
const      ll mod = 1000000007;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a ) % mod; b >>= 1;} return res;}

const int N = 1e5 + 5;
int dp[N][2][2];
int n;
string s, w;

int solve(int i, bool one, bool two) // one -> condition one  two->condition two
{
    if(i==n)
        return (one && two);
    if(dp[i][one][two]!=-1){
        return dp[i][one][two];
    }
    if(s[i]!='?' and w[i]!='?'){
        if(s[i]>w[i]){
            dp[i][one][two] = solve(i + 1, true, two);
        }else if(w[i]>s[i]){
            dp[i][one][two] = solve(i + 1, one, true);
        }else{
            dp[i][one][two] = solve(i + 1, one, two);
        }
    }else{
        dp[i][one][two] = 0;
        if(s[i]=='?' and w[i]=='?'){
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(45, solve(i+1,true,two)));
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(45, solve(i+1,one,true)));
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(10, solve(i+1,one,two)));
        }else if(s[i]=='?'){
            int b = (w[i] - '0');
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(b, solve(i+1,one,true)));
            b = 9 - b;
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(b, solve(i+1,true,two)));
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(1, solve(i+1,one,two)));
        }else if(w[i]=='?'){
            int b = (s[i] - '0');
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(b, solve(i+1,true,two)));
            b = 9 - b;
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(b, solve(i+1,one,true)));
            dp[i][one][two] = mod_add(dp[i][one][two], mod_mul(1, solve(i+1,one,two)));
        }
    }
    return dp[i][one][two];
}
void solution()
{
   cin>>n;
   cin >> s >> w;
   memset(dp, -1, sizeof(dp));

   cout << solve(0, false, false) << endl;
}

int main()
{
    Sezar;
    //tc(t) solution();
    solution();
}