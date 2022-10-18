// Problem Link: https://codeforces.com/contest/1730/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void planets()
{
    int n,c;
    cin>>n>>c;
    unordered_map<int,int> mp;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans =0;
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        if((it->second)>1) 
        {
            int x = it->second;
            if(c<=x) ans+=c;
            else ans+=x;
        }
        else ans+=1;
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
     cin >> t;
    while (t--)
        planets();
}
