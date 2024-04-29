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
    string s;
    cin >> s;
    int bb = 0;
    int B = 0;
    string ans = "";

    for (int i= s.size() - 1; i >= 0; i--)
    {

        if(s[i]=='b')
        {
            bb = bb+1;
            cout << s[i] << "   " << bb << endl;
        }
        else if(s[i]=='B'){
            B = B+1;
            cout << s[i] << "   " << B << endl;
        }
        else
        {

            if(s[i]>='a' and s[i]<='z')
            {
                //cout << s[i] << "   " << bb << endl;
                if(bb==0)
                {
                    ans += s[i];
                }
                else
                {
                    cout << s[i] << "   " << bb << endl;
                    bb--;
                    bb = max(0, bb);
                    continue;
                }
            }
            else
            {
                cout << s[i] << "   " << B << endl;

                if(B)
                {
                    B--;
                    B = max(0, B);
                    continue;
                }
                else
                {
                    ans += s[i];
                }
            }
        }
        
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

void solve(){
    string s;
    cin >> s;

    int x = 0;
    int y = 0;
    int n = s.size() - 1;
    string ans = "";
    for (int i = n; i >= 0; i--){
        if(s[i]=='b'){
            x++;
        }
        else if(s[i]=='B'){
            y++;
        }
        else{
            if(s[i]>='a' and s[i]<='z'){
                if(x==0){
                    ans += s[i];
                }
                else{
                    x--;
                    x = max(0, x);
                }
            }
            else{
                if(y==0){
                    ans += s[i];
                }
                else{
                    y--;
                    y = max(0, y);
                }
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main()
{
    Sezar;
    tc(t) solve();
    // solution();
}