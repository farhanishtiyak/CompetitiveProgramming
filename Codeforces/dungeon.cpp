// Problem Link: https://codeforces.com/problemset/problem/1463/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dungeon()
{
    int a,b,c;
    cin>>a>>b>>c;
    int sum = a+b+c;
    if(sum%9==0)
    {
        int x = sum/9;
        if(x<=a and x<=b and x<=c) 
        {
            cout<<"YES"<<endl;
            return;
        }
        else 
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    else
    cout<<"NO"<<endl;
}
int main()
{
    int t ;
    cin >> t;
    while (t--) dungeon();
}
