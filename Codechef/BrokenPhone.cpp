// Problem link: https://www.codechef.com/START55C/problems/BROKENPHONE

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,n;
        cin>>r>>n;
        if(r==n)cout<<"ANY"<<endl;
        else if(n>r) cout<<"NEW PHONE"<<endl;
        else cout<<"REPAIR"<<endl;
    }
}