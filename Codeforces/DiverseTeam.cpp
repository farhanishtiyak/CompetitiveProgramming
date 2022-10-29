// Problem link: https://codeforces.com/problemset/problem/988/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void DiverseTeam()
{
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> mp;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        mp[x]=i;
    }
    if(mp.size()>=k)
    {
        auto it = mp.begin();
        cout<<"YES"<<endl;
        for(int i=1; i<=k; i++)
        {
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    
}
int main()
{
    DiverseTeam();
}