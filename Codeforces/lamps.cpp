// Problem Link: https://codeforces.com/problemset/problem/1839/B


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

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) {
		return a.second > b.second;
	} else {
		return a.first < b.first;
	}
}

void solution()
{
	int n;
	cin >> n;
	vector<pair<int, int> > arr;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		arr.push_back({a, b});
	}

	ll ans = 0;

	sort(arr.begin(), arr.end(), compare);

	pair<int, int> p{0, 0};

	for (int i = 0; i < n; i++)
	{
		int first, second;
		first = arr[i].first;
		second = arr[i].second;


		if (first != p.first)
		{
			ans += second;
			p.first = first;
			p.second = first - 1;
		}
		else if (first == p.first and p.second > 0)
		{
			ans += second;
			p.second--;
		}
		else continue;
	}

	cout << ans << endl;
}

int main()
{
	Sezar;
	tc(t) solution();
}