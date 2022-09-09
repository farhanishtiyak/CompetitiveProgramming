// Problem link: https://codeforces.com/contest/581/problem/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int mx = max(a,b);
    int mn = min(a,b);
    mx-=mn;
    int ans = mx/2;
    cout<<mn<<" "<<ans<<endl;
}