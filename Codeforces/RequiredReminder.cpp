// Problem Link : https://codeforces.com/contest/1374/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long


void requiredReminder()
{
    int x,y,n;
    cin>>x>>y>>n;
    int ans = (n-y)/x;
    ans = ans*x;
    ans = ans + y;
    cout<<ans<<endl;
}
int main()
{
    int t ;
    cin >> t;
    while (t--) requiredReminder();
}
