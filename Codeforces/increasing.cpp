// Problem Link: https://codeforces.com/contest/1742/problem/B

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<int ,int> mp;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        bool flag = true;
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            if(it->second>1) 
            {
                flag = false;
                break;
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}