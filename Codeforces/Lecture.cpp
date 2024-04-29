// Problem link: https://codeforces.com/contest/499/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void lecture()
{
    int n,m;
    cin>>n>>m;
    unordered_map<string,string> mp;
    for(int i=0; i<m; i++)
    {
        string s,t;
        cin>>s>>t;
        int x = s.size();
        int y = t.size();
        if(x<=y) mp[s] = s;
        else mp[s] = t;
    }
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        cout<<mp[s]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--) lecture();
}

