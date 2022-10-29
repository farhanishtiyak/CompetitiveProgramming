// Problem link: https://codeforces.com/contest/556/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   int n;
   cin>>n;
   string s;
   cin>>s;
   int one=0,zero=0;
   for(int i=0; i<n; i++)
   {
       if(s[i]=='1') one++;
       else zero++;
   }
   cout<<max(one,zero)-min(one,zero)<<endl;
}