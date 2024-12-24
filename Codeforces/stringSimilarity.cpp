// Problem Link : https://codeforces.com/problemset/problem/1400/A

#include<bits/stdc++.h>
using namespace std;

void stringSimilarity()
{
    int n; 
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(int i=0; i<s.size(); i++)
    {
        mp[s[i]]++;
    }
    if(mp['0']>=n) 
    {
        for(int i=0; i<n; i++) cout<<0;
            cout<<endl;
    }
    else
    {
        for(int i=0; i<n; i++) cout<<1;
            cout<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--) stringSimilarity();
}