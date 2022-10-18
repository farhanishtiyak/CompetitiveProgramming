// Problem Link: https://codeforces.com/contest/1743/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) 
{
    return fact(n) / (fact(r) * fact(n - r));
}


void password()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int x = 10-n;
    int ans = nCr(x,2);
    ans*=6;
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    cin>>t;
   while(t--)  password();
}