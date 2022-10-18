// Problem Link: https://codeforces.com/contest/110/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
   int t=1;
   //cin>>t;
   while(t--) 
   {
       string n;
       cin>>n;
       int ans =0;
       for(int i=0; i<n.size(); i++)
       {
            if(n[i]=='4' or n[i]=='7') ans++;
       }
       bool flag = false;
       while(ans!=0)
       {
            int x = ans%10;
            if(x==7 or x==4) 
            {
                ans = ans/10;
                flag = true;
            }
            else 
            {
                flag = false;
                break;
            }
       }
       if(flag) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
   }
}