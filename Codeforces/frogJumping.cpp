// problem Link: https://codeforces.com/problemset/problem/1077/A

#include<bits/stdc++.h>
using namespace std;

void frogJumping()
{
    long long a,b,k;
    cin>>a>>b>>k;
    if(k&1)
    {
        long long  x = k/2;
        long long  y = (k/2)+1;
        x = x*b;
        y = y*a;
        long long ans = (y-x);
        cout<<ans<<endl;
    }

    else
    {
        long long  x = (k/2);
        long long  ans = (a*x) - (b*x);
        cout<<ans<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--) frogJumping();
}