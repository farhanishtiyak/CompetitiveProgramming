// Problem Link: https://codeforces.com/contest/237/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void freeCash()
{
    int n;
    cin>>n;
    int ans = 1; 
    map<pair<int,int>,int> mp;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        pair<int,int> pr = make_pair(x,y);
        mp[pr]++;
        ans = max(ans, mp[pr]);
    }
    cout<<ans<<endl;
}
int main()
{
    int t =1 ;
    //cin >> t;
    while (t--) freeCash();
}
