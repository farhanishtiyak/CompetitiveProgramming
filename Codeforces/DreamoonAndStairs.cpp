// Problem link: https://codeforces.com/contest/476/problem/A


#include <bits/stdc++.h>
using namespace std;
#define ll long long

void DreamoonAndStairs()
{
    int n,m,ans, rem;
    cin>>n>>m;
    if(n<m)
    {
        cout<<-1<<endl;
        return;
    }
    
    if(n&1) ans = n/2+1;
    else ans = n/2;

    if(ans%m==0) cout<<ans<<endl;
    else
    {
        rem = ans%m;
        ans+=(m-rem);
        cout<<ans<<endl;
    }
}
int main()
{
    int t=1;
    //cin >> t;
    while (t--) DreamoonAndStairs();
}

