#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define  tc(t)  int t; cin >> t; while (t--)
#define  ll     long long
#define  int     long long
#define  ld     long double

typedef  pair<int, int> pii;
typedef  pair<int, int> pll;
typedef  vector<int> vi;
typedef  vector<int> vll;
typedef  vector<pll> vpll;
typedef  vector<string> vs;
typedef  unordered_map<int, int> umii;
typedef  map<int, int> mii;
typedef  unordered_map<int, int> umll;
typedef  map<int, int> mll;
typedef  tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

#define    all(v)         (v).begin(),(v).end()
#define    all1(v)        (v).begin()+1,(v).end()
#define    sort0(v)       sort(all(v))
#define    pb             emplace_back
#define    ppb            pop_back
#define    mkp            make_pair


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

const      int mod = 998244353;
const      int MOD = 1000000007;
const      int INF = LLONG_MAX;

const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int inv(int i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}

int lcm(int a, int b) {return (a * b) / gcd(a, b);}

int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}

int pwr(int a, int b) {a %= mod; int res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a ) % mod; b >>= 1;} return res;}

int binaryToDecimal(string n) {string num = n; int dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value;}
string decToBinary(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}

void input(vi &a)  {for (auto &x : a) {cin >> x;}}
void output(vi &a) {for (auto &x : a) {cout << x << " ";} cout << endl;}
void output(auto x) {cout << x << endl;}
void getUnique(vi &a) {sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end());}

int stringToint(string &s) { int number = 0; for (auto ch : s) { number = (number * 10) + (ch - '0');} return number; }
int  maxx(vi &a) { return (*max_element(a.begin(), a.end())); }
int  minn(vi &a) { return (*min_element(a.begin(), a.end())); }

bool isPalindrome(string s) {int n = s.size(); for (int i = 0; i < n; i++) {if (s[i] != s[n - i - 1]) {return false;}} return true;}
bool isPrime(int n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(int n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x) {if (x >= 0) {int sr = sqrt(x); return (sr * sr == x);} return false;}

struct nodeInfo {
	int ps, ss, ts, ms;
	// ps : Prefix sum
	// ss : suffix sum
	// ts : total sum
	// ms : maximum subarray sum
};

nodeInfo merge(nodeInfo left, nodeInfo right){
    nodeInfo ans;
    ans.ps = max(left.ps, left.ts + right.ps);
    ans.ss = max(right.ss, right.ts + left.ss);
    ans.ts = left.ts + right.ts;
    vi temp = {left.ms, right.ms, left.ss + right.ps};
    ans.ms = maxx(temp);
    return ans;
}



struct segmenttree {
    int n;
    vector<nodeInfo> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        // leaf node base case
        
        if (start == ending) {
            nodeInfo currentNode;
            currentNode.ps = currentNode.ss = currentNode.ts = currentNode.ms = v[start];
            st[node] = currentNode;
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = merge(st[node * 2 + 1] , st[node * 2 + 2]);
    }


    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
           nodeInfo currentNode;
            currentNode.ps = currentNode.ss = currentNode.ts = currentNode.ms = value;
            st[node] = currentNode;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = merge(st[node * 2 + 1] , st[node * 2 + 2]);

        return;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};




void solution()
{
    int n, q;
    cin >> n >> q;
    vi arr(n);
    input(arr);
    segmenttree tree;
    tree.init(n);
    tree.build(arr);
    nodeInfo head = tree.st[0];
    vi ans = {head.ps, head.ms, head.ss, head.ts};
    output(max(0ll,maxx(ans)));

    while(q--){
        int i, v;
        cin>>i>>v;
        tree.update(i, v);
        head = tree.st[0];
        ans = {head.ps, head.ms, head.ss, head.ts};
        output(max(0ll,maxx(ans)));
    }
}

int32_t main()
{
    Sezar;
    // tc(t) solution();
    solution();
}