// Problem Link: https://codeforces.com/problemset/problem/1463/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void findTheArray()
{
    int n;
    cin>>n;
    vector<ll> arr;
    ll oddSum=0, evenSum=0;
    for(int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        if(i&1) oddSum+=x;
        else evenSum+=x;
        arr.push_back(x);
    }
    if(oddSum>evenSum)
    {
        for(int i=0;i<n; i++)
        {
            if(i&1) cout<<1<<" ";
            else cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    else
    {
        for(int i=0;i<n; i++)
        {
            if(i&1) cout<<arr[i]<<" ";
            else cout<<1<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int t ;
    cin >> t;
    while (t--) findTheArray();
}
