// Problem link: https://codeforces.com/contest/266/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    while(t--) for(int i=0; i<(n-1); i++) if(s[i]=='B' and s[i+1]=='G') swap(s[i],s[i++]);
    cout<<s<<endl;
}