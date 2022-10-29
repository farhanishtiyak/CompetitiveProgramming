// Problem link: https://codeforces.com/contest/1754/submission/177729683

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void TechnicalSupport()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int q=0, a=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='Q') q++;
        else
        {
            if(q==0) q=0;
            else q--;
        }
    }
    if(q==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--) TechnicalSupport();
}