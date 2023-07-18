// Problem link: https://codeforces.com/contest/34/problem/A 

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Reconnaissance()
{
    int n, mini = INT_MAX;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    pair<int,int> ans;
    for(int i=0; i<n; i++)
    {
        if(i==(n-1)) 
        {
            int x = abs(arr[i]-arr[0]);
            if(x<mini)
            {
                mini = x;
                ans = make_pair(1,i+1);
            }
        }
        else 
        {
            int x = abs(arr[i]-arr[i+1]);
            if(x<mini)
            {
                mini = x;
                ans = make_pair(i+1,i+2);
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--) Reconnaissance();
}

