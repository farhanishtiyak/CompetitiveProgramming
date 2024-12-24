// Problem Link: https://codeforces.com/contest/379/problem/A

#include <bits/stdc++.h>
using namespace std;

//   Method 1
void newYearCandles()
{
    int n,b;
    cin>>n>>b;
    int ans =0;
    while(n>=b)
    {
        ans+=b;
        n=n-b+1;
    }
    cout<<ans+n<<endl;
}

//   Method 2

void NewYearCandles()
{
    int n,b;
    cin>>n>>b;
    int ans = n;
    while(n>=b)
    {
        ans = ans+(n/b);
        n = (n/b)+(n%b);
    }
    cout<<ans<<endl;
}
int main()
{
    int t =1 ;
    //cin >> t;
    while (t--) NewYearCandles();
}
