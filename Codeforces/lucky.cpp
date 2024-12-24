// Problem Link: https://codeforces.com/contest/1676/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void lucky()
{
    string s;
    cin>>s;
    int firstSum =0, secondSum =0;
    for(int i=0; i<6; i++)
    {
        if(i<3)  firstSum+=(int)s[i]-'0';
        else secondSum+=(int)s[i]-'0';
    }
    if(firstSum==secondSum) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--) lucky();
}