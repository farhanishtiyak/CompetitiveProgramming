// Problem link: https://codeforces.com/contest/1740/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solution()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll ans =0;
    for(ll i=0; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i] = max(x,y);
        ans+=min(x,y);
    }
    ans*=2;
    sort(arr,arr+n);
    for(ll i=0; i<n; i++)
    {
        if(i==0) ans+=arr[i];
        if(i==(n-1)) ans+=arr[i];
        else ans+=(arr[i+1]-arr[i]);
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    cin >> t;
    while (t--) solution();
}

