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


void solution()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int different = 0, same = 0;
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (s[i] == s[j]) same++;
		else different++;

		i++;
		j--;
	}
	set<int> st;
	if (different == 0) {
		if (s.size() & 1) {
			st.insert(0);
			st.insert(1);
		}
		else st.insert(0);
	}

	st.insert(different);
	if (s.size() & 1) st.insert(different + 1);
	for (int i = 1; i <= same; i++) {
		different += 2;
		st.insert(different);
		if (s.size() & 1) st.insert(different + 1);
	}

	for (int i = 0; i <= s.size(); i++) {
		if (st.find(i) != st.end()) cout << 1;
		else cout << 0;
	}
	cout << endl;


}
int main()
{
	Sezar;
	tc(t) solution();
	//solution();
}

