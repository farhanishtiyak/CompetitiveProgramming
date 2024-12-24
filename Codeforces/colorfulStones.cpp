// Problem Link: https://codeforces.com/problemset/problem/265/A

#include<bits/stdc++.h>
using namespace std;

void colorfulStones()
{
    string s,t;
    cin>>s>>t;
    int j=0; 
    int l = t.size();
    for(int i=0; i<l; i++)
    {
        if(t[i]==s[j]) j++;
    }
    cout<<(j+1)<<endl;
}

int main()
{
    int t =1 ;
    //cin>>t;
    while(t--) colorfulStones();
}