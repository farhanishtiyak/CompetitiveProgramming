// Problem Link: https://codeforces.com/contest/1742/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sum()
{
    int a,b,c;
   cin>>a>>b>>c;
   if(a+b==c) cout<<"YES"<<endl;
   else if(b+c==a) cout<<"YES"<<endl;
   else if(c+a==b) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
 
}
int main()
{
    int t;
     cin >> t;
    while (t--)
        sum();
}