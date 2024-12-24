// Problem link: https://codeforces.com/contest/1368/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void C()
{
    ll a,b,n;
    cin>>a>>b>>n;
    ll x =0;
    int ans = 0;
    while(x<=n)
    {
        if(a>b)
        {
            b+=a;
            x = b;
            ans++;
        }
        else
        {
            a+=b;
            x=a;
            ans++;
        }
    }
    cout<<ans<<endl;

}
int main()
{
    int t;
     cin >> t;
    while (t--)
        C();
}
