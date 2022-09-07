// Problem Link: https://www.codechef.com/START55C/problems/PERMCLEAR

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    vector<int>arr;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cin>>k;
    unordered_map<int,int>mp;
    for(int i=0; i<k; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    for(auto val:arr)
    {
        if(mp[val]) continue;
        else cout<<val<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}