// Problem Link: https://codeforces.com/problemset/problem/734/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void antonAndDanik()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int anton =0, danik =0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='A') anton++;
        else danik++;
    }
    if(anton>danik) cout<<"Anton"<<endl;
    else if(danik>anton) cout<<"Danik"<<endl;
    else cout<<"Friendship"<<endl;
}
int main()
{
    int t =1;
    //cin >> t;
    while (t--) antonAndDanik();
}
