// Problem Link: https://codeforces.com/problemset/problem/1734/B


#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll int n; 
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i ; j++)
        {
            if(j==1 or j==i)
                cout<<1<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int t;
     cin >> t;
    while (t--)
        solve();
}
