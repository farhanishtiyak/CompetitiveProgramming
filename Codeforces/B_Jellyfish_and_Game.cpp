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


void solution()
{
//    ll n,m,k;
//    cin>>n>>m>>k;
//    ll j[n], g[m];
//    ll sum = 0, miniJ = INT_MAX, maxi = INT_MIN, miniG = INT_MAX, maxiJ = INT_MIN;
//    for(int i=0; i<n; i++){
//     ll x;
//     cin>>x;
//     sum+=x;
//     miniJ = min(miniJ, x);
//     maxiJ = max(maxiJ, x);
//    }
//    for(int i=0; i<m; i++){
//     ll x;
//     cin>>x;
//     maxi = max(maxi,x);
//     miniG = min(miniG,x);
//    }

//    if(k&1){
//     if(miniJ<maxi){
//         sum-=miniJ;
//     sum+=maxi;
//     }
//    }
//    else{
//     if(miniG<miniJ){
//         sum-=miniJ;
//         sum+=miniG;
//     }
//    }

//    cout<<sum<<endl;


    ll n,m,k;
    cin>>n>>m>>k;
    ll ans =0;
    // int arr[n], brr[m];
    vector<ll> arr(n), brr(m);
    for(ll i=0; i<n; i++) cin>>arr[i];
    for(ll i=0; i<m; i++) cin>>brr[i];

    sort(arr.begin(),arr.end());
    sort(brr.begin(), brr.end());

    // if(k==1){
    //     for(ll i=1; i<n; i++) ans+=arr[i];
    //     ans+=(max(arr[0],brr[m-1]));
    //     cout<<ans<<endl;
    //     return;
    // }

    if(k&1){
        for(ll i=1; i<n; i++) ans+=arr[i];
        ans+=(max(arr[0],brr[m-1]));
    }
    else{
        // for(ll i=0; i<(n-1); i++) ans+=arr[i];

        // ans+= (min(brr[0],arr[n-1]));

        ll mx = brr[m-1];
        ll mn = arr[0];
        if(mx>mn){
            arr[0] = mx;
            brr[m-1] = mn;
            sort(arr.begin(),arr.end());
            sort(brr.begin(), brr.end());
        }

        mx = arr[n-1];
        mn = brr[0];

        arr[n-1] = mn;
        brr[0] = mx;
        sort(arr.begin(),arr.end());

        for(ll i=0; i<n; i++) ans+=arr[i];
        //cout<<ans<<endl;
        
    }

    cout<<ans<<endl;
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}