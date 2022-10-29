// Problem link: https://codeforces.com/contest/1353/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void mostUnstableArray()
{
    int n,m;
    cin>>n>>m;
    if(n==1) cout<<0<<endl;
    else if(n==2) cout<<m<<endl;
    else cout<<(2*m)<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  mostUnstableArray();
}