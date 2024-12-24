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

class info {
public:
	int open, close, full;
public:
	info() {
		open = 0;
		close = 0;
		full = 0;
	}
	info(int _open, int _close, int _full) {
		open = _open;
		close = _close;
		full = _full;
	}
};

info merge(info leftNode, info rightNode)
{
	info ans = info(0, 0, 0);
	ans.open = leftNode.open + rightNode.open - min(leftNode.open, rightNode.close);
	ans.close = leftNode.close + rightNode.close - min(leftNode.open, rightNode.close);
	ans.full = min(leftNode.open, rightNode.close) + leftNode.full + rightNode.full;
	return ans;
}

void buildSGT(int index, int low, int high, string s, info segTree[])
{
	if (low == high) {
		segTree[index].open = (s[low] == '(');
		segTree[index].close = (s[low] == ')');
		segTree[index].full = 0;
		return;
	}

	int mid = (low + high) / 2;
	buildSGT(2 * index + 1, low, mid, s, segTree);
	buildSGT(2 * index + 2, mid + 1, high, s, segTree);
	segTree[index] = merge(segTree[2 * index + 1], segTree[2 * index + 2]);
}

info query(int ind, int low, int high, int l, int r, info segTree[])
{
	// no overlap
	if (high < l or r < low)
	{
		info ans = info(0,0,0);
		return ans;
	}

	// complete overlap
	if (low >= l and high <= r) return segTree[ind];

	// partial overlap
	int mid = (low + high) >> 1;
	info left = query(2 * ind + 1, low, mid, l, r, segTree);
	info right = query(2 * ind + 2, mid + 1, high, l, r, segTree);
	return merge(left, right);
}

void solution()
{
	string s;
	cin >> s;

	int m;
	cin >> m;

	int n = s.size();
	info segTree[4 * n + 1];

	buildSGT(0, 0, n - 1, s, segTree);

	while (m--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		info ans = query(0, 0, n - 1, l, r, segTree);

		cout << ans.full * 2 << endl;
	}
}

int main()
{
	Sezar;
	// tc(t) solution();
	solution();
}

