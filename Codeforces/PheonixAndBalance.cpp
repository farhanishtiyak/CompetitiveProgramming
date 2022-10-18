// Problem link: https://codeforces.com/contest/1348/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Approach 2

void pheonixAndBalance()
{
    ll n;
    cin>>n;
    ll a = pow(2,(n+1))-2;
    ll b = pow(2,(n/2))-2;
    ll firstSum = b+pow(2,n);
    ll secondSum = a - firstSum;
    cout<<firstSum-secondSum<<endl;
}
int main()
{
    //  Approach 1
    unordered_map<int,ll> ans;
    ll cnt = 2;
    for(int i=2; i<=30; i=i+2)
    {
        ans[i] = ans[i-2]+cnt;
        cnt = cnt * 2;
    }

    int t;
    cin>>t;
    while(t--)
    {
        // int n;
        // cin>>n;
        // cout<<ans[n]<<endl;
        pheonixAndBalance();
    }
}