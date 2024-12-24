// Problem Link: https://codeforces.com/contest/1726/problem/A

#include<bits/stdc++.h>
using namespace std;

void solution()
{
    int n;
    cin>>n;
    int maxi =INT_MIN;
    int mini =INT_MAX;
    int diff =INT_MIN;
    vector<int>arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x>maxi) maxi=x;
        if(x<mini) mini=x;
        arr.push_back(x);
    }

    for(int i=0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            int x = arr[i]-arr[i+1];
            if(x>diff) diff = x;
        }
    }
    maxi = maxi-arr[0];
    mini = arr[n-1]-mini;
    int ans = max(maxi,max(mini,diff));
    cout<<ans<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}