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

int cnt(int *a, int n) {
    int ans = 0;
    new_data_set St;

    for (int i = 0; i < n; i++) {
        ans += (i - St.order_of_key(a[i]));
        St.insert(a[i]);
    }

    return ans;
}

void solution()
{
    int n;
    cin >> n;

    vector<int> a, b;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.pb(x);
    }


    for (int i = 0; i < n; i++) {
        mp[a[i]] = b[i];
    }

    int firstA[n], FirstB[n];
    for (int i = 0; i < n; i++) {
        firstA[i] = i + 1;
        FirstB[i] = mp[i + 1];
    }

    int firstCnt = cnt(FirstB, n);

    // for (int i = 0; i < n; i++){
    //     cout << firstA[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++){
    //     cout << FirstB[i] << " ";
    // }
    // cout << endl;

    //cout << firstCnt << endl;

    for (int i = 0; i < n; i++) {
        mp[b[i]] = a[i];
    }

    int secondA[n], secondB[n];
    for (int i = 0; i < n; i++) {
        secondB[i] = i + 1;
        secondA[i] = mp[i + 1];
    }

    int secondCnt = cnt(secondA, n);

    //cout << secondCnt << endl;

    // //cout << firstCnt << " " << secondCnt << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << firstA[i] << " ";
    // }
    // cout << endl;

    if (firstCnt < secondCnt) {
        for (int i = 0; i < n; i++){
            cout << firstA[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++){
            cout << FirstB[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++){
            cout << secondA[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++){
            cout << secondB[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}