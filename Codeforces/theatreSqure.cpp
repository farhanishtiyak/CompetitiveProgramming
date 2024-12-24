// Problem link: https://codeforces.com/contest/1/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
   int t=1;
   //cin>>t;
   while(t--) 
   {
       ll n,m,a,x,y;
       cin>>n>>m>>a;
       if(n%a==0) x = n/a;
       else x = (n/a)+1;
       if(m%a==0) y = m/a;
       else y = (m/a)+1;
       cout<<(x*y)<<endl;
   }
}