// Problem Link:https://codeforces.com/contest/1728/problem/B

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    int arr[n+1];
    
    int value = n-2;
    for(int i=1; i<=n-2; i++)
    {
        arr[i]=value--;
    }  
    arr[n-1]=n-1;
    arr[n]=n;
    if(n&1) swap(arr[1],arr[2]);
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;  
    
        
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}