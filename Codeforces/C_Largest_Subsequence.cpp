#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt")


const ll MOD = 1000000000+7;
const int N = 405;
ll modular_exp(ll a,ll b,ll mod){//mod should be <32 bit
    ll ans=1;
    while(b>0){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
void solve(int cs)
{
    int n;
    string s;
    cin >> n >> s;
    vector<char> mx(s.size());
    vector<pii> res;
    mx[n - 1] = s[n - 1];
    for(int i = n - 2; i >= 0; --i)
    {
        mx[i] = max(mx[i + 1], s[i]);
    }
    vector<int> indx;
    for(int i = 0; i < n; ++i)
    {
        if(mx[i] == s[i])
        {
            res.push_back({(int)s[i], i});
            indx.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    sort(indx.begin(), indx.end());

    for(int i = 0; i < indx.size(); ++i)
    {
        s[indx[i]] = res[i].first;
    }
    string s2 = s;
    sort(s2.begin(), s2.end());
    if(s == s2)
    {
        int rem = 0;
        for(auto e: res){
            if(e.first == res.back().first)
                ++rem;
        }
        cout << (int)indx.size() - rem << '\n';
        return;
    }
    cout << "-1\n";

}
int main()
{
    fastio;
//    cout << fixed << setprecision(15);
    int T=1;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        solve(t+1);
    }
    return 0;
}
/*

*/
