// Problem link: https://codeforces.com/problemset/problem/148/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
   int t=1;
   //cin>>t;
   while(t--) 
   {
       int k,l,m,n,d;
       cin>>k>>l>>m>>n>>d;
       int ans =0;
       for(int i=1; i<=d; i++)
       {
            int x = i%k==0 or i%l==0 or i%m==0 or i%n==0;
            if(!x) ans++;
       }
       cout<<(d-ans)<<endl;
   }
}