// Problem Link: 

#include<bits/stdc++.h>
using namespace std;
void minimalSquare()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
    {
        int ans = max(a,(2*b));
        ans*=ans;
        cout<<ans<<endl;
    }
    else
    {
        int ans = max(2*a,b);
        ans*=ans;
        cout<<ans<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        minimalSquare();
    }
}