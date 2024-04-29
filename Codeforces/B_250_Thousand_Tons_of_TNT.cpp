#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Sezar ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

#define all(v) (v).begin(), (v).end()
#define all1(v) (v).begin() + 1, (v).end()
#define sort0(v) sort(all(v))
#define pb emplace_back
#define ppb pop_back
#define mkp make_pair

#define for0(i, n) for (int i = 0; i < n; i++)
#define forr(i, a, b) for (i = a; i <= b; i++)

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
#define infinity 9999999999999
const ll mod = 998244353;

ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll pwr(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solution2()
{
    int n;
    cin >> n;
    // vector<int> arr;
    vector<ll> sum;
    sum.pb(0);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        // arr.pb(c);
        sum.pb(c + 0LL + sum[sum.size() - 1]);
    }

    vector<int> div;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // cout << i << " ";
            div.pb(i);
            if (i != n / i)
            {
                div.pb(n / i);
            }
        }
    }

    // cout << "sum" << endl;
    // for (auto it : sum)
    //     cout << it << " ";
    // cout << endl;

    // cout << "divisors" << endl;
    // for (auto it : div)
    //     cout << it << " ";
    // cout << endl;
    // cout << endl;

    // ll ans = 0;
    //  for (int i = 0; i < div.size(); i++)
    //  {
    //      ll mx = INT_MIN, mn = INT_MAX;
    //      int cnt = 0;
    //      ll cur = 0;
    //      for (int j = 0; j < arr.size(); j++)
    //      {
    //          if (cnt == div[i])
    //          {
    //              cnt = 0;
    //              mx = max(mx, cur);
    //              mn = min(mn, cur);
    //              cur = 0;
    //          }

    //         cur += arr[j];
    //         cnt++;
    //     }
    //     ans = max(ans, abs(mx - mn));
    // }

    ll ans = 0;

    for (int i = 0; i < div.size(); i++)
    {
        ll mx = INT_MIN, mn = LLONG_MAX;
        for (int j = 0; j < sum.size(); j += div[i])
        {
            if (j - div[i] >= 0)
            {
                mx = max(mx, sum[j] - sum[j - div[i]]);
                mn = min(mn, sum[j] - sum[j - div[i]]);
            }
        }

        // cout << mx << "   " << mn << endl
        //      << endl;

        if (mn != INT_MAX and mx != LLONG_MAX)
        {
            ans = max(ans, abs(mx - mn));
        }
    }

    cout << ans << endl;
}

int main()
{
    Sezar;
    tc(t) solution2();
    // solution();
}