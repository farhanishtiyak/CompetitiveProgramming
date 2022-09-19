// Problem Link: https://codeforces.com/contest/1733/problem/A

// Try it again

#include<bits/stdc++.h>
using namespace std;
#define MOD (int) 1e9+7
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define tc(t) int t; cin >> t; while (t--)
#define int int
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
#define endl "\n"

void consecutiveSum()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    ll ans =0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        arr[i%k] = max(arr[i%k],x);
    }
    for(int i=0; i<k; i++) ans+=arr[i];
        
    cout<<ans<<endl;
}

int main()
{
    fio;
    tc(t) consecutiveSum();
}