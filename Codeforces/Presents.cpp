#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        mp[x] = i;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        cout<<it->second<<" ";
    }
    cout<<endl;
}