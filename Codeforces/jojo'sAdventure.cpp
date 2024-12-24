// Problem link: https://codeforces.com/contest/1820/problem/B

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
	string s;
	cin >> s;
	ll totalConsecutiveOne = 0 , indexOfFirstZero = -1, indexOfLastZero = -1, count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1') count++;
		else
		{
			totalConsecutiveOne = max(totalConsecutiveOne, count);
			count = 0;
			if (indexOfFirstZero == -1) indexOfFirstZero = i;
			if (indexOfLastZero < i) indexOfLastZero = i;
		}
	}

	totalConsecutiveOne = max(totalConsecutiveOne, count); // if all are one's then else block will not gonna execute

	if (totalConsecutiveOne == s.size())
	{
		ll anss = totalConsecutiveOne * totalConsecutiveOne;
		cout << anss << endl;
		return;
	}

	ll totalConsecutiveOneBeforeFirstZeroAndAfterLastZero = indexOfFirstZero + (s.size() - indexOfLastZero - 1);

	totalConsecutiveOne = max(totalConsecutiveOne, totalConsecutiveOneBeforeFirstZeroAndAfterLastZero);

	ll halfOfTotalConsecutiveOne = ceil_div(totalConsecutiveOne, 2);

	ll ans = halfOfTotalConsecutiveOne * (totalConsecutiveOne - halfOfTotalConsecutiveOne + 1);

	cout << ans << endl;

}

int main()
{
	Sezar;
	tc(t) solution();
	//solution();
}