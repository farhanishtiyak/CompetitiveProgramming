// Problem Link: https://codeforces.com/problemset/problem/1554/A

#include<bits/stdc++.h>
using namespace std;

//  Brute Force Approach  
// Time complexity : O(n*n)
void cherry()
{
    int n; 
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x; 
        arr.push_back(x);
    }

    long long int ans =INT_MIN;

    for(int i=0; i<n; i++)
    {
        int mx=arr[i], mn = arr[i];
        
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]>mx) mx = arr[j];
            if(arr[j]<mn) mn = arr[j];
            long long int m = mx*1ll*mn;
            ans = max(ans, m);
        }
        
    }

    cout<<ans<<endl;
}

// Optimal 
// Time complexity : O(n)
void CHERRY()
{
    int n; 
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x; 
        arr.push_back(x);
    }
    long long ans = INT_MIN;

    for(int i=0; i<n-1; i++)
    {
       long long mx = arr[i]*1ll*arr[i+1];
       ans = max(ans,mx);
    }

    cout<<ans<<endl;
}



int main()
{
    int t;
    cin>>t;
    while(t--) CHERRY();
}