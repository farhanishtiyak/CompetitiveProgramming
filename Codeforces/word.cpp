// Problem link: https://codeforces.com/problemset/problem/59/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int up=0,low=0;
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        int c = (int)s[i];
        if(c>=65&&c<=90) up++;
        else low++;
    }
    if(up>low)
    {
        for(int i=0; i<n; i++)
        {
            char c = s[i]&'_';
            cout<<c;
        }
        cout<<endl;
    }
    else 
    {
        for(int i=0; i<n; i++)
        {
            char c = s[i]|' ';
            cout<<c;
        }
        cout<<endl;
    }
}