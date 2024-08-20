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
    ll n,m;
    cin >> n >> m;
    vector<ll> p,t,ans;
    for (int i = 0; i < n+m+1; i++){
        ll x;
        cin >> x;
        p.pb(x);
    }
    for (int i = 0; i < n+m+1; i++){
        ll x;
        cin >> x;
        t.pb(x);
    }

    vector<int> pt(n + m+1, 0), tt(n + m+1, 0);
    vector<pair<int, int>> ch(n+m+1,{0,0});
    set<int> p_ind, t_ind;
    ll sum = 0, pc = n, tc=m;
    for (int i = 1; i < n + m+1; i++){
        if(p[i]>t[i] and pc>0){
            pt[i] = 1;
            sum += p[i];
            pc--;
            p_ind.insert(i);
        }else if(p[i]<t[i] and tc>0){
            sum += t[i];
            tt[i] = 1;
            tc--;
            t_ind.insert(i);
        }else{
            if(pc>0){
                pt[i] = 1;
                sum += p[i];
                pc--;
                p_ind.insert(i);
            }else{
                sum += t[i];
                tt[i] = 1;
                tc--;
                t_ind.insert(i);
            }
        }
        ch[i] = make_pair(pc, tc);
    }
    ans.pb(sum);

    for (int i = 1; i < n + m + 1; i++){
        if(pt[i]==1){
            sum -= p[i];
            pt[i] = 0;
            if(p[i-1]>=p[i] or ch[i].second==0 or p[i-1]>=t[i-1]){
                sum += p[i - 1];
                pt[i - 1] = 1;
                auto it = p_ind.find(i);
                p_ind.erase(it);
                p_ind.insert(i - 1);
            }else{
                sum += t[i - 1];
                tt[i - 1] = 1;
                ch[i - 1] = make_pair(ch[i - 1].first - 1, ch[i - 1].second + 1);
                auto it = t_ind.end();
                it--;
                int ind = *it;
                t_ind.erase(it);
                tt[ind] = 0;
                sum -= t[ind];
                sum += p[ind];
                pt[ind] = 1;
                p_ind.insert(ind);
                ch[ind] = make_pair(ch[ind].first + 1, ch[ind].second - 1);
            }
        }else{
            sum -= t[i];
            tt[i] = 0;
            if(t[i-1]>=t[i] or ch[i].first==0 or t[i-1]>=p[i-1]){
                sum += t[i - 1];
                tt[i - 1] = 1;
                auto it = t_ind.find(i);
                t_ind.erase(it);
                t_ind.insert(i - 1);
            }else{
                sum += p[i - 1];
                pt[i - 1] = 1;
                ch[i - 1] = make_pair(ch[i - 1].first + 1, ch[i - 1].second - 1);
                auto it = p_ind.end();
                it--;
                int ind = *it;
                p_ind.erase(it);
                pt[ind] = 0;
                sum -= p[ind];
                sum += t[ind];
                tt[ind] = 1;
                t_ind.insert(ind);
                ch[ind] = make_pair(ch[ind].first - 1, ch[ind].second + 1);
            }
        }
        ans.pb(sum);
    }
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}