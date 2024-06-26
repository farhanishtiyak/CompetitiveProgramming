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
	int x[n + 1], y[n + 1], z[n + 1];
	int a[n + 1], b[n + 1], c[n + 1];
	int d[n + 1], e[n + 1], f[n + 1];
	a[0] = 0;
	b[0] = 0;
	c[0] = 0;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		x[i] = h;
		a[i] = max(a[i - 1], h);
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		y[i] = x;
		b[i] = max(b[i - 1], x);
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		z[i] = x;
		c[i] = max(c[i - 1], x);
	}

	d[n] = x[n];
	e[n] = y[n];
	f[n] = z[n];
	for (int i = n - 1; i >= 1; i--) {
		d[i] = max(d[i + 1], x[i]);
		e[i] = max(e[i + 1], y[i]);
		f[i] = max(f[i + 1], z[i]);
	}

	// for (auto i : a) cout << i << " ";
	// cout << endl;
	
	for (auto i : b) cout << i << " ";
	cout << endl;
	cout << "-------------------" << endl;
	for (auto i : c) cout << i << " ";
	cout << endl;
	cout << "-------------------" << endl;
	cout << "-------------------" << endl;
	for (auto i : e) cout << i << " ";
	cout << endl;
	cout << "-------------------" << endl;
	for (auto i : f) cout << i << " ";
	cout << endl;

	int ans = INT_MIN;
	for (int i = 2; i < n; i++) {
		int res = a[i] + max(e[i + 1], b[i - 1]) + max(f[i + 1], c[i - 1]);
		ans = max(ans, res);
	}
	cout << ans << endl;
}

int main()
{
	Sezar;
	tc(t) solution();
	// solution();
}