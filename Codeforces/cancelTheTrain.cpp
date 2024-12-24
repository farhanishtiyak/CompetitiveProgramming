// Problem Link: https://codeforces.com/problemset/problem/1453/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void cancelTheTrain()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans =0;

    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==2) ans++;
    }

    cout<<ans<<endl;
}
int main()
{
    int t ;
    cin >> t;
    while (t--) cancelTheTrain();
}
