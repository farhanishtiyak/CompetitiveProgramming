// Problem Link: https://codeforces.com/contest/520/problem/A

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_set<char>st;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++) st.insert(s[i]&'_');
    if(st.size()==26) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}