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

int query(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solution()
{
    vector<int> v = {4, 8, 15, 16, 23, 42};
	vector<int> a(4);
 
	for (int i = 0; i < 4; i++) {
		a[i] = query(i + 1, i + 2);
	}

   do {
		bool can = 1;
		for (int i = 0; i < 4; i++) {
			if (a[i] != v[i]*v[i + 1]) {
				can = 0;
			}
		}
 
		if (can == 1) {
			cout << "! ";
			for (auto x : v)cout << x << " ";
			return;
		}
	}
	while (next_permutation(v.begin(), v.end()));
}

int main()
{
    Sezar;
    //tc(t) solution();
    solution();   
}

// #include<bits/stdc++.h>

// #define int long long int
// #define F first
// #define S second
// #define pb push_back

// using namespace std;

// int query(int x, int y) {
// 	cout << "? " << x << " " << y << endl;
// 	int ans;
// 	cin >> ans;
// 	return ans;
// }

// int32_t main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	int a = query(1, 2);
// 	int b = query(2, 3);
// 	int c = query(3, 4);
// 	int d = query(4, 5);


// 	vector<int> v = {4 , 8, 15, 16, 23, 42};

// 	do {
// 		if (v[0]*v[1] == a
// 		        && v[1]*v[2] == b
// 		        && v[2]*v[3] == c
// 		        && v[3]*v[4] == d) {
// 			cout << "! ";
// 			for (auto x : v) cout << x << " ";
// 			cout << endl;
// 		}
// 	}
// 	while (next_permutation(v.begin(), v.end()));

// 	return 0;
// }