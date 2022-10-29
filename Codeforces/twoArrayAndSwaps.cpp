// Problem link: https://codeforces.com/contest/1353/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void twoArrayAndSwaps()
{
    int n,m;
    cin>>n>>m;
    int arr[n],brr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) cin>>brr[i];
    sort(arr,arr+n);
    sort(brr,brr+n,greater<int>{});
    int ans =0;
    for(int i=0; i<m; i++) ans+=max(arr[i],brr[i]);
    for(int i=m; i<n; i++) ans+=arr[i];
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  twoArrayAndSwaps();
}