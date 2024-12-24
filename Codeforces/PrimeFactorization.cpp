// Problem Link: https://codeforces.com/problemset/problem/162/C

#include<bits/stdc++.h>
using namespace std;
#define MOD (int) 1e9+7
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define tc(t) int t; cin >> t; while (t--)
#define int int
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
#define endl "\n"

void PrimeFactorization()
{
    int n;
    cin>>n;
    vi prime_fact;
    for(int i=2; i*i<=n; i++)
    {
        while(n%i==0)
        {
            prime_fact.pb(i);
            n/=i;
        }
    }
    if(n>1) prime_fact.pb(n);

    int size = prime_fact.size();
    for(int i=0; i<size; i++)
    {
        if(i==(size-1)) cout<<prime_fact[i]<<endl;
        else cout<<prime_fact[i]<<"*";
    }
}
int main()
{
    fio;
    //tc(t) 
    PrimeFactorization();
}