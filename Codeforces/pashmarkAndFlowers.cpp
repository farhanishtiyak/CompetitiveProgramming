// Problem link: 

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pashmarkAndFlowers()
{
    ll n,maxi=INT_MIN, mini=INT_MAX,ans;
    cin>>n;
    ll arr[n];
    unordered_map<ll, ll> mp;
    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]>maxi) maxi = arr[i];
        if(arr[i]<mini) mini = arr[i];
        mp[arr[i]]++;
    }
    if(maxi==mini) 
    {
        ll n = mp[maxi];
        ans = n*(n-1)/2;
    }
    else ans = mp[maxi]*mp[mini];
    cout<<(maxi-mini)<<" "<<ans<<endl;
}
int main()
{
    int t=1;
    //cin >> t;
    while (t--) pashmarkAndFlowers();
}

