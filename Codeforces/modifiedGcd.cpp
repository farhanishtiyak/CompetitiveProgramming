#include<bits/stdc++.h>
using namespace std;
#define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define  tc(t)  int t; cin >> t; while (t--)
#define  ll     long long

typedef  vector<int> vi;
typedef  vector<ll> vll;
typedef  pair<int, int> pii;
typedef  pair<ll, ll> pll;

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

void factor(int n, map<int, int> &factors, int gcd) {
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i <= gcd) factors[i]++;
			if ((n / i) <= gcd and i != (n / i)) factors[(n / i)]++;
		}
	}
}

void solution()
{
	int a, b, q;
	cin >> a >> b >> q;

	int gcd = __gcd(a, b);

	vector<int> commonFactors;
	map<int, int> factors;

	factor(a, factors, gcd);
	factor(b, factors, gcd);


	for (auto it : factors) {
		if (it.second == 2) commonFactors.pb(it.first);
		//cout << it.first << "   " << it.second << endl;
	}

	// cout << endl << endl;
	// for (auto it : commonFactors) cout << it << " ";
	// cout << endl << endl << "ans" << endl;

	while (q--) {

		int l, r;
		cin >> l >> r;

		if (l > gcd) {
			cout << -1 << endl;
			continue;
		}
		if (r >= gcd) {
			cout << gcd << endl;
			continue;
		}

		auto ind = lower_bound(all(commonFactors), r) - commonFactors.begin();
		if (commonFactors[ind] > r) ind--;

		if (commonFactors[ind] >= l) cout << commonFactors[ind] << endl;
		else cout << -1 << endl;

	}

}

int main()
{
	Sezar;
	// tc(t) solution();
	solution();
}

