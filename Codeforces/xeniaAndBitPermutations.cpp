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

void updateSGT(int index, int low, int high, int i, int val, int operation, vector<int> &seg)
{
	if (low == high) {
		seg[index] = val;
		return;
	}

	int mid = (low + high) >> 1;
	if (i <= mid) updateSGT(2 * index + 1, low, mid, i, val, !operation, seg);
	else updateSGT(2 * index + 2, mid + 1, high, i, val, !operation, seg);
	if (operation == 1) {
		seg[index] = seg[2 * index + 1] | seg[2 * index + 2];
	}
	else seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
}

void buildSGT(int index, int low, int high, vector<int> &arr, vector<int> &seg, int operation)
{
	if (low == high) {
		seg[index] = arr[low];
		return;
	}

	int mid = (low + high) >> 1;
	buildSGT(2 * index + 1, low, mid, arr, seg, !operation);
	buildSGT(2 * index + 2, mid + 1, high, arr, seg, !operation);
	if (operation == 1) {
		seg[index] = seg[2 * index + 1] | seg[2 * index + 2];
	}
	else seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
}

void solution()
{
	int n, m;
	cin >> n >> m;
	int elements = pow(2, n);
	vector<int> arr(elements);
	vector<int> seg(4 * elements + 5);

	int orr = n & 1 ? 1 : 0;


	for (int i = 0; i < elements; i++) cin >> arr[i];

	buildSGT(0, 0, elements - 1, arr, seg, orr);

	while (m--) {
		int index , value;
		cin >> index >> value;
		updateSGT(0, 0, elements - 1, index - 1, value, orr, seg);
		cout << seg[0] << endl;
	}

}
int main()
{
	Sezar;
	// tc(t) solution();
	solution();
}

