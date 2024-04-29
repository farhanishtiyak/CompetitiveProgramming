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


const int N = 1020;

int spf[N];   // Smallest Prime Factor
vector<int> primes;
void sieve() {
	for (int i = 2; i < N; i++) {
		if (spf[i] == 0) spf[i] = i, primes.push_back(i);
		int sz = primes.size();
		for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
			spf[i * primes[j]] = primes[j];
		}
	}
}



void solution(int t)
{
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.pb(x);
	}

	vector<vector<int>> factors;

	for (auto it : primes) {
		vector<int> f;
		int cnt = 0;
		for (auto i : arr) {
			if (i % it == 0) {
				f.pb(1);
				cnt++;
			}
			else f.pb(0);
		}

		if (cnt >= k) factors.pb(f);
	}

	// cout << "********factors*********" << endl;

	// for (auto outer : factors) {
	// 	for (auto inner : outer) {
	// 		cout << inner << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<vector<int>> sumOfFactors;

	for (auto it : factors) {
		vector<int> sum;
		sum.pb(0);
		for (auto itt : it) {
			int last = sum[sum.size() - 1];
			last += itt;
			sum.pb(last);
		}
        sumOfFactors.pb(sum);
	}

	// cout << "********Sum of factors*********" << endl;

	// for (auto outer : sumOfFactors) {
	// 	for (auto inner : outer) {
	// 		cout << inner << " ";
	// 	}
	// 	cout << endl;
	// }
    
    vector<pair<int,int>> probableAns;
    int ans = 0;
    for(int i=0; i<sumOfFactors.size(); i++){
        for(int j=0; j<sumOfFactors[i].size(); j++){
            if(sumOfFactors[i][j]>=k){
                int search = sumOfFactors[i][j]-k;
                int remove = lower_bound(sumOfFactors[i].begin(), sumOfFactors[i].end(), search)-sumOfFactors[i].begin();
                int cur = j-remove;
                if(cur>k) {
                    //ans = max(ans, cur);
                    probableAns.pb(make_pair(j,cur));
                }
            }
        }
    }

    for(int i=0; i<probableAns.size(); i++){
        int ind = probableAns[i].first;
        int cur = probableAns[i].second;
        bool take = true;
        for(int j=0; j<sumOfFactors.size(); j++){
            if(sumOfFactors[j][ind]>=cur) take = false;
        }
        if(take) ans = max(ans, cur);
    }

    cout<<"Case "<<t<<": "<<ans<<endl;

}

int main()
{
	Sezar;
	int t;
	cin >> t;
	sieve();
	for (int i = 1; i <= t; i++) {
		solution(i);
	}
}