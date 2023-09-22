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
	ll n, k;
	cin >> n >> k;
	ll mini = INT_MAX;
	ll fruits[n], height[n];
	for (int i = 0; i < n; i++) 
	{
		cin >> fruits[i];
		mini  = min(mini, fruits[i]);
	}
	for (int j = 0; j < n; j++) cin >> height[j];

	vector<vector<ll>> subFruits(n, vector<ll>());

	ll ind = 0;

	bool divisibleFound = false;
	for (int i = 0; i < n - 1; i++)
	{
		if (height[i] % height[i + 1] == 0)
		{
			subFruits[ind].pb(fruits[i]);
			divisibleFound = true;
		}
		else
		{
			if (divisibleFound)
			{
				subFruits[ind].pb(fruits[i]);
				divisibleFound = false;
				ind++;
			}
		}
	}
	if (divisibleFound) {
		subFruits[ind].pb(fruits[n - 1]);
		ind++;
	}

	subFruits.resize(ind);
	
	ll ans = (mini<=k)?1:0;

	for(ll i=0; i<subFruits.size(); i++)
	{
		ll sum = 0;
		if(subFruits[i].size()>0) sum = subFruits[i][0];
		else continue;

		ll x = 0, y=0, curAns = 0;
		while(y<subFruits[i].size())
		{
			while(x<=y and sum>k)
			{
				sum-=subFruits[i][x];
				x++;
			}

			if(sum!=0 and sum<=k)
			{
				curAns = y-x+1;
				ans = max(ans,curAns);
			}
			y++;
			if(y<subFruits[i].size()) sum+=subFruits[i][y];
		}

	}

	// cout<<"subFruits size: "<<subFruits.size()<<endl;

	// for (int i = 0; i <=ind; i++)
	// {
	// 	for (int j = 0; j < subFruits[i].size(); j++)
	// 	{
	// 		cout << subFruits[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout<<"Maximum : "<<k<<endl;
	// cout<<"Ans: ";
	cout<<ans<<endl;
	//cout<<endl;
}

int main()
{
	Sezar;
	tc(t) solution();
}