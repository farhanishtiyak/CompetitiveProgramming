// Problem Link: https://codeforces.com/contest/1696/problem/A

#include <bits/stdc++.h>
//#include <cmath>
using namespace std;

void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>v;
  for(int i=0; i<n; i++)
  {
    int x;
    cin>>x;
    v.push_back(x);
  }
  int maxi = INT_MIN;
  for(int i=0; i<n; i++)
  {
    int x = v[i]|k;
    if(x>maxi) maxi =x;
  }
  cout<<maxi<<endl;
}
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    solve();
  }
  
}