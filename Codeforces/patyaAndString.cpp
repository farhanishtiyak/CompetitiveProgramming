// Problem Link: https://codeforces.com/problemset/problem/112/A

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    for(int i=0; i<n; i++)
    {
        s1[i] = s1[i] & '_';
        s2[i] = s2[i] & '_';
    }
    int x = s1.compare(s2);
    if(x<0) cout<<-1<<endl;
    else if(x>0) cout<<1<<endl;
    else cout<<0<<endl;
}