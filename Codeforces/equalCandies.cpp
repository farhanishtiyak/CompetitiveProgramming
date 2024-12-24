// Problem Link: https://codeforces.com/contest/1676/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void equalCandies()
{
    int n;
    cin>>n;
    ll ans =0;
    vector<int> arr;
    ll mini = INT_MAX;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        if(x<mini) mini = x;
    }
    for(int i=0; i<n; i++)
    {
        ans+=(arr[i]-mini);
    }
    cout<<ans<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--) equalCandies();
}