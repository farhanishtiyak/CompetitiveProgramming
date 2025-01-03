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
	string s, t;
	cin >> s >> t;

	int lowerCase[26], upperCase[26], ls[26], us[26], lower[26], upper[26];
	for (int i = 0; i < 26; i++)
	{
		lowerCase[i] = 0;
		upperCase[i] = 0;
		ls[i] = 0;
		us[i] = 0;
		lower[i] = 0;
		upper[i] = 0;
	}

	for (int i = 0; i < t.size(); i++)
	{
		int x = t[i];

		if (x >= 65 and x <= 90)
		{
			upperCase[t[i] - 'A']++;
			upper[t[i] - 'A']++;
		}
		else
		{
			lowerCase[t[i] - 'a']++;
			lower[t[i] - 'a']++;
		}
	}

	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i];
		if (x >= 65 and x <= 90) us[s[i] - 'A']++;
		else ls[s[i] - 'a']++;
	}

	int yay = 0, whoops = 0, yay2 = 0;

	for (int i = 0; i < 26; i++) yay2 += ((min(ls[i], lower[i])) + (min(us[i], upper[i])));

	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i];
		if (x >= 65 and x <= 90)
		{
			if (upperCase[s[i] - 'A'] > 0)
			{
				yay++;
				upperCase[s[i] - 'A']--;
			}
			else
			{
				if (lowerCase[s[i] - 'A'] > 0)
				{
					lowerCase[s[i] - 'A']--;
					whoops++;
				}
			}
		}
		else
		{
			if (lowerCase[s[i] - 'a'] > 0)
			{
				yay++;
				lowerCase[s[i] - 'a']--;
			}
			else {
				if (upperCase[s[i] - 'a'] > 0)
				{
					upperCase[s[i] - 'a']--;
					whoops++;
				}
			}
		}
	}

	yay += whoops;
	whoops = yay - yay2;

	cout << yay2 << " " << whoops << endl;


}

int main()
{
	Sezar;
	// tc(t) solution();
	solution();
}