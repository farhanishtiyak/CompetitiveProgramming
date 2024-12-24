// Problem link: https://codeforces.com/problemset/problem/499/A
///==========================================================================
///
///                   Bismillah ir-Rahman ir-Rahim
///
/// ==========================================================================
///
///                    Md. Farhan Ishtiyak Sezar
///
///                    Dept. of Computer Science and Engineering
///                    Jagannath University , Bangladesh
///
///                    ID    : Md.Farhan_Ishtiyak_Sezar
/// ==========================================================================

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void watchingMovie()
{
    int n,a;
    cin>>n>>a;
    map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x] = y;
    }
    int value = 1, ans =0;
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        while((value+a)<=it->first) value+=a;
        ans+=(it->second - value + 1);
        value = it->second +1;
    }
    cout<<ans<<endl;
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--) watchingMovie();
}

