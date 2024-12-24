// Problem link: https://codeforces.com/contest/34/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sale()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);
    int ans =0;
    for(int i=0; i<m; i++) 
    {
        if(arr[i]<0) ans+=arr[i];
    }
    if(ans>0) cout<<0<<endl;
    else cout<<abs(ans)<<endl;
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--) sale();
}

