// Problem Link: https://codeforces.com/contest/1409/problem/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b) cout<<0<<endl;
        else if(a>b)
        {
            a-=b;
            int ans = a/10;
            if(a%10==0) cout<<ans<<endl;
            else cout<<(ans+1)<<endl;
        }
        else
        {
            b-=a;
            int ans = b/10;
            if(b%10==0) cout<<ans<<endl;
            else cout<<(ans+1)<<endl;
        }
    }
}