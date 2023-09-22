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

void update(int ind, int low, int high, int l, int r, vector<int> &seg, int x, vector<int> &ans)
{
	if (low == high and seg[ind] == -1) {
		if(low>=l and high<=r){
			if (low == x) return;
			else {
				seg[ind] = x;
				ans[low] = x;
				return;
			}
		}
	}

	// no overlap
	if (high < l or r < low) return;
	// complete overlap
	if (low >= l and high <= r) {
		if (seg[ind] == -1) {
			int mid = (low + high) / 2;
			update(2 * ind + 1, low, mid, l, r, seg, x,ans);
			update(2 * ind + 2, mid + 1, high, l, r, seg, x,ans);
			if (seg[2 * ind + 1] != -1 and seg[2 * ind + 2] != -1) seg[ind] = 0;
			else return;
		}
		else return;
	}

	// partial overlap

	int mid = (low + high) / 2;
	update(2 * ind + 1, low, mid, l, r, seg, x,ans);
	update(2 * ind + 2, mid + 1, high, l, r, seg, x,ans);
	if (seg[2 * ind + 1] != -1 and seg[2 * ind + 2] != -1) seg[ind] = 0;

}

void solution()
{
	int n, m;
	cin >> n >> m;

	vector<int> seg(4 * n + 1, -1);
	vector<int> ans(n+1,0);

	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		update(0, 1, n, l, r, seg, x, ans);
	}

	// cout<<endl<<"SEGMENT TREE"<<endl;
	// for (int i = 0; i < 15; i++) cout <<"index "<<i<<" : "<< seg[i] << endl;

	// cout<<endl<<"ANS"<<endl;
	for (int i = 1; i <=n; i++) cout <<ans[i]<<" ";
	cout<<endl;

}

int main()
{
	Sezar;
	// tc(t) solution();
	solution();
}