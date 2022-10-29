// Problem link: https://codeforces.com/contest/451/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void GameWithSticks()
{
    int n,m;
    cin>>n>>m;
    int x = min(n,m);
    if(x&1) cout<<"Akshat"<<endl;
    else cout<<"Malvika"<<endl;
}

int main()
{
    int t=1;
    //cin>>t;
    while(t--) GameWithSticks();
}