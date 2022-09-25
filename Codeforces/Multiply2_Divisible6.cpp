// Problem Link: https://codeforces.com/contest/1374/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long


void multiply2_divisible6()
{
     int n;
     cin>>n;
     int ans =0;

     if(n&(n-1)==0 and n>1)
     {
        cout<<-1<<endl;
        return;
     }
     
     while(n!=1)
    {
        if(n%6==0)
        {
            n=n/6;
            if(n&(n-1)==0 and n>1)
            {
                cout<<-1<<endl;
                return;
            }
            ans++;
        }

        else if(n%6==3)
        {
            n=n*2;
            ans++;
        }
        else
        {
            cout<<-1<<endl;
            return;
        }
     }

     cout<<ans<<endl;
}
int main()
{
    int t ;
    cin >> t;
    while (t--) multiply2_divisible6();
}
