// Problem Link: https://codeforces.com/problemset/problem/1454/B

#include<bits/stdc++.h>
using namespace std;

void uniqueBidAuction()
{
    int n;
    cin>>n;
    unordered_map<int, int> mp;
    std::vector<int> v;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        v.push_back(x);
    }
    int ans = INT_MAX;
    for(auto it= mp.begin(); it!=mp.end(); it++)
    {
        if(it->second ==1)
        {
            if(it->first < ans) ans = it->first;
        }
    }

    if(ans == INT_MAX)
    {
        cout<<-1<<endl;
    }

    else
    {
        for(int i=0; i<n ; i++)
        {
            if(v[i]==ans) 
            {
                cout<<(i+1)<<endl;
                break;
            }
        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        uniqueBidAuction();
    }
}