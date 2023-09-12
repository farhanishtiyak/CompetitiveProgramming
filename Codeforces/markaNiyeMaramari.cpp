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
#define    forr(i,a,b)    for(int i=a;i<=b;i++)

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

ll markaNiyeMaramari(ll curTeam, set<ll> &st, vector<vector<ll>> &arr, ll n ,vector<ll> &dp) {
	if (curTeam == n) {
		for (ll i = 1; i <= n; i++) {
			if (arr[curTeam][i] == 1 and st.find(i) == st.end()) {
				// st.insert(i);
				// for (auto it : st) {
				// 	cout << it << " ";
				// }
				// cout << endl;
				// st.erase(i);
				return 1;
			}
		}
		return 0;
	}

    if(dp[curTeam]!=-1) return dp[curTeam];

	ll validTeam = 0;

	for (ll i = 1; i <= n; i++) {

		if (arr[curTeam][i] and st.find(i) == st.end()) {
			st.insert(i);
			validTeam += markaNiyeMaramari(curTeam + 1, st, arr, n,dp);
			st.erase(i);
		}
	}
	return dp[curTeam] = validTeam;
}

void solution()
{
	ll n;
	cin >> n;
	if (n == 1) {
		ll x;
		cin >> x;
		if (x == 1) {
			cout << 1 << endl;
			return;

		}
		else {
			cout << 0 << endl;
			return;
		}
	}
    
	bool allZero = false;
	vector<vector<ll>> arr(n + 1, vector<ll>(n + 1));

	for (ll i = 1; i <= n; i++) {
		ll cnt = 0;
		for (ll j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) cnt++;
		}
		if (cnt == n) allZero = true;
	}

	if (allZero) {
		cout << 0 << endl;
		return;
	}

	ll curTeam = 1, ans = 0;

    vector<ll> dp(n+1, -1);

	set<ll> st;
	for (ll i = 1; i <= n; i++) {
		if (arr[curTeam][i]) {
			st.insert(i);
			ans += markaNiyeMaramari(curTeam + 1, st, arr, n, dp);
			st.erase(i);
		}
	}

	cout << ans << endl;

}
int main()
{
	Sezar;
	tc(t) solution();
	//solution();
}

