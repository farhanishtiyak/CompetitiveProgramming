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

// vector<bool> prime(1e7+10, true);


// void SieveOfEratosthenes(int n)
// {
//     //memset(prime, true, sizeof(prime));
//     prime[0] = false;
//     prime[1] = false;
//     for (int p=2; p*p<=n; p++)
//     {
//         if (prime[p] == true)
//         {
//             for (int i=p*2; i<=n; i += p)
//                 prime[i] = false;
//         }
//     }
// }

// class SGTree {
// 	vector<int> seg;
// public:
// 	SGTree(int n) {
// 		seg.resize(4 * n + 1);
// 	}

// 	void build(int ind, int low, int high, int arr[]) {
// 		if (low == high) {
// 			// seg[ind] = arr[low];
//             if(prime[arr[low]]) seg[ind] = 0;
//             else seg[ind] = 1;
// 			return;
// 		}

// 		int mid = (low + high) / 2;
// 		build(2 * ind + 1, low, mid, arr);
// 		build(2 * ind + 2, mid + 1, high, arr);
// 		seg[ind] =(seg[2 * ind + 1]+seg[2 * ind + 2]);
// 	}

// 	int query(int ind, int low, int high, int l, int r, int call) {
// 		// no overlap
// 		// l r low high or low high l r
//         //cout<<"L: "<<l<<" R: "<<r<<endl;
//         //cout<<"Low: "<<low<<" high: "<<high<<endl;
// 		if (r < low || high < l) {
//             return 0;
//         }

// 		// complete overlap
// 		// [l low high r]
// 		if (low >= l && high <= r) return seg[ind];

// 		int mid = (low + high) >> 1;
// 		int left = query(2 * ind + 1, low, mid, l, r, call);
// 		int right = query(2 * ind + 2, mid + 1, high, l, r, call);
// 		if(call==0){
//             if(right>0) return left+right;
//             else return INT_MIN;
//         }
//         else{
//             if(left>0) return left+right;
//             else return INT_MIN;
//         }
// 	}
// 	void update(int ind, int low, int high, int i, int val) {
// 		if (low == high) {
// 			// seg[ind] = val;
//             if(prime[val]) seg[ind] = 1;
//             else seg[ind] = 0;
// 			return;
// 		}

// 		int mid = (low + high) >> 1;
// 		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
// 		else update(2 * ind + 2, mid + 1, high, i, val);
// 		seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
// 	}

//     void print(){
//         for(int i=0; i<9; i++){
//             cout<<seg[i]<<" ";
//         }
//         cout<<endl;
//     }
// };



// void solution()
// {
//    int n,q;
//    cin>>n>>q;

//    int arr[n];
//    int maxi = INT_MIN;
//    for(int i=0; i<n; i++){
//     cin>>arr[i];
//     maxi = max(maxi,arr[i]);
//    }

//    SieveOfEratosthenes(maxi+5);

// //    for(int i=2; i<=maxi; i++){
// //     if(prime[i]) cout<<i<<" ";
// //    }
// //    cout<<endl;

//    SGTree st(n);
//    st.build(0,0,n-1,arr);

//     st.print();

//    while(q--){
//     int type;
//     cin>>type;
//     if(type==1){
//         int ind;
//         cin>>ind;
//         ind--;
//         int left = 0;
//         if(ind-1>=0) left+=st.query(0,0,n-1,0,ind-1,0);
//         int right = 0;
//         if(ind+1<n) right+=(st.query(0,0,n-1,ind+1,n-1,1));

//         //cout<<"left: "<<left<<" right: "<<right<<endl;
//         int ans = max(left, right);
//         cout<<ans<<endl;
//     }
//     else{
//         int ind, val;
//         cin>>ind>>val;
//         ind--;
//         st.update(0,0,n-1,ind,val);
//     }
//    }
// }

// int main()
// {
//     Sezar;
//     tc(t) solution();
//     // solution();
// }





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


// vector<bool> prime(1e7+10, true);

// void SieveOfEratosthenes(int n)
// {
//     //memset(prime, true, sizeof(prime));
//     prime[0] = false;
//     prime[1] = false;
//     for (int p=2; p*p<=n; p++)
//     {
//         if (prime[p] == true)
//         {
//             for (int i=p*2; i<=n; i += p)
//                 prime[i] = false;
//         }
//     }
// }

// void solution()
// {
    
//    int n;
//    cin>>n;
//    int q;
//    cin>>q;
//    set<int> st;
//    int arr[n+1];
//    for(int i=1; i<=n; i++){
//         int x;
//         cin>>x;
//         arr[i] = x;
//         if(prime[x]) st.insert(i);
//    }

//    //cout<<st.size()<<endl;

//     while (q--)
//     {
//         int type;
//         cin>>type;
//         if(type==1){
//             int ind;
//             cin>>ind;

//             if(st.size()==0) {
//                 cout<<n-1<<endl;
//                 continue;
//             }

//             int primeIndex;
//             int left;
//             auto lb = lower_bound(st.begin(), st.end(), ind);
//             if(lb==st.begin()){
//                 left = ind-1;
//             }
//             else{
//                 lb--;
//                 primeIndex = *lb;
//                 left = ind-primeIndex-1;
//             }

//             //cout<<left<<endl;

//             // Right

//             auto ub = upper_bound(st.begin(), st.end(), ind);
//             int right;
//             if(ub==st.end()){
//                 right = n-ind;
//             }
//             else{
//                 right = *ub-ind-1;
//             }
//             cout<<left+right<<endl;
//             //cout<<right<<endl;
//             // if(ub==st.end()){
//             //     cout<<"End"<<endl;
//             // }
//             // else cout<<*ub<<endl;

//             //cout<<*(upper_bound(st.begin(),st.end(), 1))<<endl;

//         }
//         else{
//             int ind, val;
//             cin>>ind>>val;
//             if(prime[val]) 
//             {
//                 st.insert(ind);
//                 arr[ind] = val;
//             }
//             else{
//                 if(prime[arr[ind]]){
//                     st.erase(ind);
//                     arr[ind] = val;
//                 }
//             }
//         }
//     }
    

// }

// int main()
// {
//     Sezar;
//     SieveOfEratosthenes(1e7+6);
//     tc(t) solution();
//     // solution();
// }



#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;

int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}

int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    set<int> se;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (spf[a[i]] == a[i]) {
        se.insert(i);
      }
    }
    while (q--) {
      int ty; cin >> ty;
      if (ty == 1) {
        int x; cin >> x;
        int ans = 0;
        auto it = se.upper_bound(x);
        if (it == se.end()) ans += n - x;
        else ans += (*it) - x - 1;
        it = se.lower_bound(x);
        if (it == se.begin()) ans += x - 1;
        else ans += x - (*(--it)) - 1;
        cout << ans << '\n';
      }
      else {
        int i, y; cin >> i >> y;
        if (spf[a[i]] == a[i]) {
          se.erase(i);
        }
        a[i] = y;
        if (spf[a[i]] == a[i]) {
          se.insert(i);
        }
      }
    }
  }
  return 0;
}
