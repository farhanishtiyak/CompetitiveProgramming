// Problem Link: https://codeforces.com/contest/1692/problem/B

#include<bits/stdc++.h>
using namespace std;

void allDistinct()
{
    int n;
    cin>>n;
    unordered_set<int>arr;
    for(int i=0 ;i<n; i++)
    {
        int x;
        cin>>x;
        arr.insert(x);
    }

    int ans = 0;
    n=n-arr.size();
    n=n%2;
    ans = arr.size()-n;

    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        allDistinct();
    }
}