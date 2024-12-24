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

bool check(vector<int>&temp, vector<int> & brr, vector<int> & arr,int y, multimap<int, int> &mp, multimap<int,int> &rest){
    
    // for (int i = 0; i < y; i++){
        
    // }

    bool possible = true;

    int i = arr.size() - 1;
    int cnt = arr.size() - y;
    while(cnt--){
        auto it = lower_bound(temp.begin(), temp.end(), brr[i]);
        if(it== temp.end()){
            // cout << "NO" << endl;
            // return;
            possible = false;
            break;
        }
        else{
            int val = *it;
            rest.insert({val, brr[i]});
            //cout << val << "  " << brr[i] << endl;
            temp.erase(it);
        }
        i--;
    }

    int a = 0;
    for (int i = 0; i < y; i++){
        if(temp[a]<=brr[i]){
            possible = false;
            break;
        }
        else{
            mp.insert({temp[a], brr[i]});
            a++;
        }
    }

    return possible;
}

void solution()
{
    int n;
    cin >> n;
    int y;
    cin >> y;

    vector<int> arr;
    vector<int> temp;
    vector<int> brr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.pb(x);
        temp.pb(x);
    }

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        brr.pb(x);
    }

    sort(brr.begin(), brr.end());
    sort(temp.begin(), temp.end());

    vector<int> b = brr;
    vector<int> t = temp;

    bool possible = true;

    multimap<int, int> mp;

    for (int i = 0; i < y; i++){
        auto it = upper_bound(temp.begin(), temp.end(), brr[i]);
        if(it== temp.end()){
            // cout << "NO" << endl;
            // return;
            possible = false;
            break;
        }
        else{
            int val = *it;
            mp.insert({val, brr[i]});
            //cout << val << "  " << brr[i] << endl;
            temp.erase(it);
        }
    }

    // for(auto it: temp)
    //     cout << it << " ";
    // cout << endl;

    multimap<int, int> rest;
    int a = 0;
    for (int i = y; i < n; i++){
        if(temp[a]>brr[i]){
            possible = false;
            break;
        }
        else{
            rest.insert({temp[a], brr[i]});
            a++;
        }
    }

    // for(auto it: mp)
    //     cout << it.first << "  " << it.second << endl;
    // cout << "***********" << endl;
    // for(auto it: rest)
    //     cout << it.first << "  " << it.second << endl;

    if(possible){
        cout << "YES" << endl;

        for (int i = 0; i < n; i++){

            auto mit = mp.find(arr[i]);
            if (mit != mp.end()) {
                cout << mit->second << " "; 
                mp.erase(mit);
            }
            else{
                auto rit = rest.find(arr[i]);
                if(rit != rest.end()){
                    cout << rit->second << " ";
                    rest.erase(rit);
                }
            }
        }
        cout << endl;
    }
    else{
        if(y!=0){
            mp.clear();
            rest.clear();
            possible = check(t, b, arr, y, mp, rest);
            if(possible){
                cout << "YES" << endl;

                for (int i = 0; i < n; i++){

                    auto mit = mp.find(arr[i]);
                    if (mit != mp.end()) {
                        cout << mit->second << " "; 
                        mp.erase(mit);
                    }
                    else{
                        auto rit = rest.find(arr[i]);
                        if(rit != rest.end()){
                            cout << rit->second << " ";
                            rest.erase(rit);
                        }
                    }
                }
                cout << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
}

int main()
{
    Sezar;
    tc(t) solution();
    // solution();
}