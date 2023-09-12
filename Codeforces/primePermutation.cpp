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

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


void solution()
{
	string s;
	cin >> s;
	int arr[26] = {0};
	for (int i = 0; i < s.size(); i++) arr[s[i] - 'a']++;
	int maxCount = 0, index = -1;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > maxCount) {
			maxCount = arr[i];
			index = i;
		}
	}

	unordered_set<int> st;

	for (int i = 2; i <= s.size(); i++) {
		if (isPrime(i)) {

			int curCount = 0;
			for (int j = 2; j <= (s.size() / i); j++) {
				if (i * j <= s.size()) {
					curCount++;
					st.insert(i * j);
				}
				else break;
			}

			if (curCount > 0) st.insert(i);

		}
	}

	vector<char> ans(s.size() + 1, '1');
	for (auto ch : st) {
		ans[ch] = char(index + 'a');
		arr[index]--;
	}

	for (int i = 1; i < ans.size(); i++) {
		if (ans[i] == '1') {
			for (int j = 0; j < 26; j++) {
				if (arr[j]) {
					ans[i] = char(j + 'a');
					arr[j]--;
					break;
				}
			}
		}
	}



	if (st.size() <= maxCount) {
		cout << "YES" << endl;
		for (int i = 1; i < ans.size(); i++) cout << ans[i];
	}
	else cout << "NO" << endl;



}
int main()
{
	Sezar;
	// tc(t) solution();
	solution();
}

