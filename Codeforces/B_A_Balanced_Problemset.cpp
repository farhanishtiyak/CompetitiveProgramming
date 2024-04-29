#include<bits/stdc++.h>

using namespace std;
#define  ll     long long

int main()
{
    ll t;
    cin >> t;
    while(t--){
        ll x, n;
        cin >> x >> n;
        ll till = x / n;
        ll ans = INT_MIN;
        for (ll i = 1; i*i<=x; i++){
            if(x%i==0){
                ll t = x / i;
                if(t>=n){
                    ans = max(ans, i);
                }
                if(i>=n){
                    ans = max(ans, t);
                }
            }
        }
            cout << ans << endl;
    }
}