// Problem Link: https://codeforces.com/contest/1728/problem/A

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int maxi = INT_MIN;
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x>maxi) 
        {
            maxi = x;
            mp[x]=i+1;
        }
    }
    cout<<mp[maxi]<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}