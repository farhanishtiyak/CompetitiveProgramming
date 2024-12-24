#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define  tc(t)  int t; cin >> t; while (t--)
#define  ll     long long
#define  ld     long double

typedef  pair<int, int> pii;
typedef  pair<ll, ll> pll;
typedef  vector<int> vi;
typedef  vector<ll> vll;
typedef  vector<pll> vpll;
typedef  vector<string> vs;
typedef  unordered_map<int, int> umii;
typedef  map<int, int> mii;
typedef  unordered_map<ll, ll> umll;
typedef  map<ll, ll> mll;
typedef  tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

#define    all(v)         (v).begin(),(v).end()
#define    all1(v)        (v).begin()+1,(v).end()
#define    sort0(v)       sort(all(v))
#define    pb             emplace_back
#define    ppb            pop_back
#define    mkp            make_pair
#define    ff             first
#define    ss             second

#define    forf(i,n)      for (int i = 0; i < n; i++)
#define    forb(i,n)      for (int i = n-1; i >= 0; i--)
#define    for1(i, n)     for (int i = 1; i <= n; i++)
#define    loop(i,a,b)    for (int i = a; i < b; i++)
#define    rloop(i,a,b)   for (int i = a ; i>=b;i--)

#define    endl           "\n"
#define    yes            cout << "YES" << endl
#define    no             cout << "NO" << endl
#define    minus          cout << "-1" << endl
#define    inf            9223372036854775807

const      ll mod = 998244353;
const      ll MOD = 1000000007;
const      ll INF = LLONG_MAX;

const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a * b) / gcd(a, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a ) % mod; b >>= 1;} return res;}

ll binaryToDecimal(string n) {string num = n; ll dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value;}
string decToBinary(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}

void input(vi &a)  {for (auto &x : a) {cin >> x;}}
void output(vi &a) {for (auto &x : a) {cout << x << " ";} cout << endl;}
void output(auto x) {cout << x << endl;}
void getUnique(vi &a) {sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end());}

int stringToint(string &s) { int number = 0; for (auto ch : s) { number = (number * 10) + (ch - '0');} return number; }
int  maxx(vi &a) { return (*max_element(a.begin(), a.end())); }
int  minn(vi &a) { return (*min_element(a.begin(), a.end())); }

bool isPalindrome(string s) {int n = s.size(); for (int i = 0; i < n; i++) {if (s[i] != s[n - i - 1]) {return false;}} return true;}
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(ll n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}


void solution()
{
    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    vi mxs(n);
    mxs[n - 1] = arr[n - 1];

    for(int i=n-2; i>=0; i--){
        if(arr[i]<=arr[i+1]){
            mxs[i] = mxs[i + 1] + 1;
        }else{
            mxs[i] = max(arr[i], mxs[i + 1]+1);
        }
    }

    int mx = maxx(mxs);
    output(mx);
    // output(mxs);
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}