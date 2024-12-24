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


// Shahajalal Shohag


const int N = 20;

int spf[N];   // Smallest Prime Factor
vector<int> primes;
void sieve() {
	for (int i = 2; i < N; i++) {
		if (spf[i] == 0) spf[i] = i, primes.push_back(i);
		int sz = primes.size();
		for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
			spf[i * primes[j]] = primes[j];
		}
	}
}
void solution()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	int ans = 0;
	int e = 0, o = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] & 1) o++;
		else e++;
	}
	if (k == 2) {
		if (e) cout << 0 << endl;
		else cout << 1 << endl;
	}
	else if (k == 4) {
		if (e = 0) cout << 2 << endl;
		else if (e == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else if (k == 3) {
		int dif = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 3 == 0) {
				cout << 0 << endl;
				return;
			}
			else {
				int q = arr[i] / 3;
				q++;
				q *= 3;
				dif = min(dif, abs(q - arr[i]));
			}
		}
		cout << dif << endl;
	}
	else {
		int dif = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 5 == 0) {
				cout << 0 << endl;
				return;
			}
			else {
				int q = arr[i] / 5;
				q++;
				q *= 5;
				dif = min(dif, abs(q - arr[i]));
			}
		}
		cout << dif << endl;
	}

}

int main()
{
	Sezar;
	sieve();
	tc(t) solution();
	// solution();
}