// Problem link: https://codeforces.com/contest/478/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int fact(int n);
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

void TimeLimitExit() // This will Give TLE
{
    int n,m;
    cin>>n>>m;
    int maximum = nCr(n-m+1,2);
    int minimum =0;

        int x = n/m;
        int y = n%m;
        if(y==0)
        {
            minimum = nCr(x,2)*m;
        } 
        else
        {
            minimum = nCr(x+1,2)*y + nCr(x,2)*(m-y);

        }                

    cout<<minimum<<" "<<maximum<<endl;
}

void RandomTeams()
{
    ll n,m;
    cin>>n>>m;
    ll maximum = (n-m+1)*(n-m)/2;
    ll minimum =0;

        ll x = n/m;
        ll y = n%m;
        if(y==0)
        {
            minimum = (x*(x-1)/2)*m;  
        } 
        else
        {
            minimum = (x*(x+1)/2)*y + (x*(x-1)/2)*(m-y);

        }                

    cout<<minimum<<" "<<maximum<<endl;
}
int main()
{
    RandomTeams();
}