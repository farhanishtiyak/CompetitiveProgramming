// Problem Link : https://codeforces.com/contest/1092/problem/A

#include<bits/stdc++.h>
using namespace std;

void UniformString()
{
   int n,k;
   cin>>n>>k; 

   int m = min(n,k);
   while(n>0)
   {
        char ch = 'a';
        int x = min(n,m);
        for(int i=1; i<=x; i++)
        {
            cout<<ch;
            ch++;
        }
        n = n-m;
   }
   cout<<endl;
   
}
int main()
{
    int t =1;
    cin>>t;
    while(t--) UniformString();
}