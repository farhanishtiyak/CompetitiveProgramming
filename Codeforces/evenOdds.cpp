// Problem Link: https://codeforces.com/problemset/problem/318/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k;
    cin>>n>>k;
    long long int r;
    if(n%2==0) r =n/2;
    else r = (n/2)+1;
    if(r>=k) 
    {
        long long int ans = 2*k-1;
        cout<<ans<<endl;
    }
    else 
    {
        r = k-r;
        cout<<2*1LL*r<<endl;
    }
}