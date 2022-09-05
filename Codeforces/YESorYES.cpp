// Problem Link: https://codeforces.com/contest/1703/problem/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        for(int i=0; i<s.size(); i++)
        {
            s[i] = s[i]&'_';
        }
        if(s.compare("YES"))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
