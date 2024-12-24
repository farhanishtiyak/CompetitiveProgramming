// Problem Link: https://codeforces.com/problemset/problem/1303/A

#include<bits/stdc++.h>
using namespace std;

void ErasingZeros()
{
   string s;
   cin>>s;
   int n = s.size();
   int first =-1, last = -1; 
   bool flag = true;

   for(int i=0; i<n; i++)
   {
      if(s[i]=='1') 
      {
        if(flag) 
        {
            first = i;
            flag = false;
        }
        else last = i;
      }
   }
   int ans =0;
   if(first>-1)
   {
       for(int i=first; i<=last; i++)
     {
        if(s[i]=='0') ans++;
     }
   }
   cout<<ans<<endl;
   
}
int main()
{
    int t;
    cin>>t;
    while(t--) ErasingZeros();
}