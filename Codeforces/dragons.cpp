// Problem link: https://codeforces.com/contest/230/problem/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int strength , n;
    cin>>strength>>n;
    multimap<int,int>mp;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        mp.insert(make_pair(x,y));
    }
    bool flag = false;
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        if(strength>it->first) strength+=it->second;
        else 
        {
            flag = true;
            break;
        }
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}