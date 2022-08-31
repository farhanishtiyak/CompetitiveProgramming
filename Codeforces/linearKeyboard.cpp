// Problem link: https://codeforces.com/problemset/problem/1607/A

#include<bits/stdc++.h>
using namespace std;

void solution()
{
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(int i=0;i<s.size(); i++)
    {
        mp[s[i]]=i+1;
    }
    string q;
    cin>>q;
    char pre = q[0];
    int answer =0;
    for(int i=0; i<q.size(); i++)
    {
        char ch = q[i];
        int x = mp[ch];
        x = abs(x-mp[pre]);
        answer+=x;
        pre = q[i];
    }
    cout<<answer<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}