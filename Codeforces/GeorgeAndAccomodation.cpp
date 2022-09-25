//Problem Link: https://codeforces.com/problemset/problem/467/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void georgeAndAccomodation()
{
    int n;
    cin>>n;
    int ans =0;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        if(y-x>=2) ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    int t =1;
    //cin >> t;
    while (t--) georgeAndAccomodation();
}
