// Problem Link : https://codeforces.com/problemset/problem/456/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_multimap<int,int> mp;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        mp.insert({a,b});
    }
    for(auto value = mp.begin(); value !=mp.end(); ++value)
    {
        if(value->second>value->first) 
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }
    cout<<"Poor Alex"<<endl;
}