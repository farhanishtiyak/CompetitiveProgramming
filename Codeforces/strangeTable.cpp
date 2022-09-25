// Problem link: https://codeforces.com/problemset/problem/1506/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void strangeTable()
{
    ll n,m,x;
    cin>>n>>m>>x;

    ll col;
    ll row;
    ll check = x%n;


    if(check ==0)
    {
        row = n;
        col = x/n;
    }
    else
    {
        row = check;
        col = (x/n)+1;
    }
    ll ans = (row-1)*m+col;
    cout<<ans<<endl;

}
int main()
{
    int t ;
    cin >> t;
    while (t--) strangeTable();
}
