// Problem Link: https://codeforces.com/contest/510/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    bool flag = true;
    for(int i=1; i<=n; i++)
    {
        if(i&1)
        {
            for(int i=1; i<=m; i++) cout<<"#";
            cout<<endl;
        }
        else
        {
            if(flag)
            {
                for(int i=1; i<=m; i++)
                {
                    if(i==m)cout<<"#";
                    else cout<<".";
                }
                cout<<endl;
                flag=false;
            }
            else 
            {
                for(int i=1; i<=m; i++)
                {
                    if(i==1)cout<<"#";
                    else cout<<".";
                }
                cout<<endl;
                flag=true;
            }
        }
    }
}