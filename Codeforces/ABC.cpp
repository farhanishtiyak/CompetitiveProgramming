// Problem Link: https://codeforces.com/problemset/problem/1632/A

#include<bits/stdc++.h>
using namespace std;

void ABC()
{
    int n;
    cin>>n; 
    string s;
    cin>>s;
    if(n==2)
    {
        if(s[0]==s[1]) 
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if(n>2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main()
{
    int t; 
    cin>>t;
    while(t--) ABC();
}