// Problem Link: https://codeforces.com/problemset/problem/615/D

//   This Problem is correct for smaller number of values. 
//   This will not work for larger number of values since 
//   the number is multiplier of the given prime factorization 
//   number. So this will overflow. 
//   ************Code needs to be optimized*************

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void multipliers()
{
    ll m; 
    cin>>m;
    ll n =1;
    int M = 1e9+7;
    for(int i=1; i<=m; i++)
    {
        ll x;
        cin>>x;
        n = n*x;
    }

    vector<ll> divisors;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            divisors.push_back(i);
            if(n % (n/i)==0)
            {
                if(n/i != i) divisors.push_back((n/i));
            }
        }
    }
    int ans = 1; 
    for(auto val : divisors)  ans = (ans*val)%M;
        
    cout<<ans<<endl;
}

int main()
{
    int t =1 ;
    //cin >> t;
    while (t--) multipliers();
}
