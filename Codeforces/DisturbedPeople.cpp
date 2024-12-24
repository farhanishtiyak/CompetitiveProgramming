// Problem Link: https://codeforces.com/contest/1077/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void disturedPeople()
{
    int n;
    cin>>n;
    int ans =0;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=1; i<(n-1); i++)
    {
        if(arr[i]==0)
        {
            if(arr[i-1]==1 and arr[i+1]==1)
            {
                arr[i+1]=0;
                ans++;
                i++;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t =1;
    //cin >> t;
    while (t--) disturedPeople();
}
