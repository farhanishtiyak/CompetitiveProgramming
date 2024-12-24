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


void solution()
{
	int n, k;
	cin >> n >> k;

	priority_queue<int, vector<int> , greater<int> > minPq;
	priority_queue<pii, vector<pii> , greater<pii> > maxPq;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 10 == 0) {
			maxPq.push({0, x});
		}
		else {
			int q = x / 10;
			int newX = (q + 1) * 10;
			int diff = newX - x;
			maxPq.push({diff, x});
		}
	}

	// while (!maxPq.empty()) {
	// 	cout << maxPq.top().second << " " << maxPq.top().first << endl;
	// 	maxPq.pop();
	// }

	while (!maxPq.empty()) {

		pii cur = maxPq.top();
		maxPq.pop();

		if (cur.first == 0) {
			minPq.push(cur.second);
		}

		else {
			int diff = cur.first;
			if (k <= diff) {
				cur.second += k;
				k = 0;
				minPq.push(cur.second);
			}
			else {
				minPq.push((cur.second + diff));
				k -= diff;
			}
		}
	}

	// while (!minPq.empty()) {
	// 	cout << minPq.top() << " ";
	// 	minPq.pop();
	// }
	// cout << endl;


	ll ans = 0;

	while (!minPq.empty()) {
		int cur = minPq.top();
		minPq.pop();
		int rem = 100 - cur;
		if (k <= rem) {
			cur += k;
			ans += (cur / 10);
			k = 0;
		}
		else {
			k -= rem;
			ans += 10;
		}
	}

	cout << ans << endl;

}

int main()
{
	Sezar;
	// tc(t) solution();
	solution();
}

