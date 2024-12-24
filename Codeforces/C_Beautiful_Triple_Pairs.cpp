// // #include<bits/stdc++.h>
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>

// // using namespace std;
// // using namespace __gnu_pbds;

// // #define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// // #define  tc(t)  int t; cin >> t; while (t--)
// // #define  ll     long long

// // typedef  vector<int> vi;
// // typedef  vector<ll> vll;
// // typedef  pair<int, int> pii;
// // typedef  pair<ll, ll> pll;
// // typedef tree<int, null_type, less<int>, rb_tree_tag,
// //         tree_order_statistics_node_update>
// //         new_data_set;

// // #define    all(v)         (v).begin(),(v).end()
// // #define    all1(v)        (v).begin()+1,(v).end()
// // #define    sort0(v)       sort(all(v))
// // #define    pb             emplace_back
// // #define    ppb            pop_back
// // #define    mkp            make_pair

// // #define    for0(i,n)      for (int i = 0; i < n; i++)
// // #define    forr(i,a,b)    for(i=a;i<=b;i++)

// // #define    yes            cout << "YES" << endl;
// // #define    no             cout << "NO" << endl;
// // #define    endl           "\n"
// // #define    infinity       9999999999999
// // const      ll mod = 998244353;

// // ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

// // ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

// // ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

// // ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

// // ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}

// // ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

// // ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a ) % mod; b >>= 1;} return res;}


// // void solution()
// // {
// //     ll n;
// //     cin >> n;
// //     vector<ll> arr;
// //     for (ll i = 0; i < n; i++){
// //         ll x;
// //         cin >> x;
// //         arr.pb(x);
// //     }

// //     vector<vector<ll>> pr;

// //     vector<ll> v(3);
// //     v[0] = arr[0];
// //     v[1] = arr[1];
// //     v[2] = arr[2];
// //     pr.pb(v);
// //     for (ll i = 1; i+3<=n; i++){
// //         v[0] = arr[i];
// //         v[1] = arr[i + 1];
// //         v[2] = arr[i + 2];
// //         pr.pb(v);
// //     }

// //     sort(pr.begin(), pr.end());
// //     for(auto x : pr){
// //         for(auto y : x){
// //             cout << y << " ";
// //         }
// //         cout << endl;
// //     }

// //     auto matched = [&](ll a, ll b, ll c, ll i) -> pair<ll,ll>
// //     {
// //         ll cnt = 0;
// //         for (; i < pr.size(); i++)
// //         {
// //             ll x = pr[i][0];
// //             ll y = pr[i][1];
// //             ll z = pr[i][2];
// //             if(a==x and b==y and c!=z)
// //             {
// //                 cnt++;
// //                 continue;
// //             }else if(a==x and b!=y and c==z)
// //             {
// //                 cnt++;
// //                 continue;
// //             }else if(a!=x and b==y and c==z)
// //             {
// //                 cnt++;
// //                 continue;
// //             }else{
// //                 break;
// //             }
// //         }

// //         //cout << cnt << endl;

// //         return make_pair(cnt,i);
// //     };

// //     ll i = 0;
// //     ll ans = 0ll;
// //     for (; i < pr.size();){
// //         ll a = pr[i][0];
// //         ll b = pr[i][1];
// //         ll c = pr[i][2];

// //         pair<ll,ll> len = matched(a, b, c, i + 1);
// //         ans += (len.first * (len.first + 1)) / 2;
// //         i = len.second;
// //     }
// //     cout << ans << endl;
// // }

// // int main()
// // {
// //     Sezar;
// //     tc(t) solution();
// //     // solution();
// // }




// #include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define  tc(t)  int t; cin >> t; while (t--)
// #define  ll     long long

// typedef  vector<int> vi;
// typedef  vector<ll> vll;
// typedef  pair<int, int> pii;
// typedef  pair<ll, ll> pll;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//         tree_order_statistics_node_update>
//         new_data_set;

// #define    all(v)         (v).begin(),(v).end()
// #define    all1(v)        (v).begin()+1,(v).end()
// #define    sort0(v)       sort(all(v))
// #define    pb             emplace_back
// #define    ppb            pop_back
// #define    mkp            make_pair

// #define    for0(i,n)      for (int i = 0; i < n; i++)
// #define    forr(i,a,b)    for(i=a;i<=b;i++)

// #define    yes            cout << "YES" << endl;
// #define    no             cout << "NO" << endl;
// #define    endl           "\n"
// #define    infinity       9999999999999
// const      ll mod = 998244353;

// ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

// ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

// ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

// ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}

// ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

// ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a ) % mod; b >>= 1;} return res;}


// void solution()
// {
//    ll array_size;
//         cin >> array_size;
//         vector<ll> numbers(array_size);
//         for (ll &num : numbers)
//             cin >> num;


//         map<pair<ll, ll>, ll> first_pair, second_pair, third_pair;
//         map<tuple<ll, ll, ll>, ll> first_triplet_count, second_triplet_count, third_triplet_count;
//         ll result = 0;
//         for (ll i = 0; i < array_size - 2; ++i)
//         {
//             ll current = numbers[i];
//             ll next = numbers[i + 1];
//             ll after_next = numbers[i + 2];
//             first_pair[{current, next}]++;
//             second_pair[{next, after_next}]++;
//             third_pair[{current, after_next}]++;
//             tuple<ll, ll, ll> triplet = make_tuple(current, next, after_next);
//             first_triplet_count[triplet]++;
//             second_triplet_count[triplet]++;
//             third_triplet_count[triplet]++;
//             result += first_pair[{current, next}] - first_triplet_count[triplet];
//             result += second_pair[{next, after_next}] - second_triplet_count[triplet];
//             result += third_pair[{current, after_next}] - third_triplet_count[triplet];
//         }
//         cout << result << endl;
// }

// int main()
// {
//     Sezar;
//     tc(t) solution();
//     // solution();
// }








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
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &i : arr) {
		cin >> i;
	}

	vector<map<array<int, 2>, vector<int>>> mp(3);

	for (int i = 0; i < n - 2; i++) {
		mp[0][ {arr[i], arr[i + 1]}].pb(arr[i + 2]);
		mp[1][ {arr[i], arr[i + 2]}].pb(arr[i + 1]);
		mp[2][ {arr[i + 1], arr[i + 2]}].pb(arr[i]);
	}

	ll ans = 0ll;
	for (int i = 0; i < 3; ++i) {
		for (auto value : mp[i]) {
			// cout << "Key: {" << key[0] << ", " << key[1] << "} => Values: ";
			set<int> st;
			for (int v : value.second) {
				ans += st.size();
				st.insert(v);
			}
		}
	}
	cout << ans << endl;

}

int main()
{
	Sezar;
	tc(t) solution();
}