//Problem Link: https://codeforces.com/contest/1476/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       if(k==1) cout<<1<<endl;
       else if(n>k) {
           if(n%k==0) cout<<1<<endl;
           else cout<<2<<endl;
       }
       else
       {
        if(k%n==0) cout<<(k/n)<<endl;
        else
        {
            int x = (k/n)+1;
            cout<<x<<endl;
        }
       }
    }
}
