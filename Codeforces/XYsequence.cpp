// Problem link: https://codeforces.com/contest/1657/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void XYsequence()
{
    ll n,B,x,y;
    cin>>n>>B>>x>>y;
    int arr[n+1];
    arr[0]=0;
    for(int i=1; i<=n; i++)
    {
        ll a = arr[i-1]+x;
        ll b = arr[i-1]-y;
        if(a<=B) arr[i] = a;
        else arr[i] = b;
    }
    for(int i=0; i<=n; i++) cout<<arr[i]<<" ";
        cout<<endl<<endl;
    int ans =0;
    for(int i=0; i<=n; i++) ans+=arr[i];
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  XYsequence();
}