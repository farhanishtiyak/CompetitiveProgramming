// Problem Link: https://codeforces.com/problemset/problem/540/A

#include<bits/stdc++.h>
using namespace std;

void combinationLock()
{
    int n;
    cin>>n; 
    string s;
    cin>>s;
    string t;
    cin>>t;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int num = abs((int)t[i]-(int)s[i]);
        if(num<=5) ans+=num;
        else
        {
            int mn = min((int)s[i], (int)t[i]);
            int mx = max((int)s[i], (int)t[i]);
            num=mn+(10-mx);
            ans+=num;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int t =1 ;
    //cin>>t;
    while(t--) combinationLock();
}