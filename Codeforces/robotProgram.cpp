// Problem Link: https://codeforces.com/problemset/problem/1452/A

#include<bits/stdc++.h>
using namespace std;

void robotProgram()
{
    int x,y;
    cin>>x>>y;
    if(x==0 && y==0) 
    {
        cout<<0<<endl;
        return;
    }
    if(x==y)
    {
        cout<<(x+y)<<endl;
        return;
    }
    int ans = max(x,y);
    ans = (2*ans)-1;
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--) robotProgram();
}