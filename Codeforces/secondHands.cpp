#include<bits/stdc++.h>
using namespace std;
const int N=101;


void solve(int t)
{
    int arr[N] = {0};
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        arr[x]++;
    }
    int mx=0;
    mx = *max_element(arr,arr+N);
    if(mx>2)
    {
        cout<<"Case #"<<t<<": NO"<<endl;
        return;
    }
    else
    {
        if(n>(2*k))
        {
            cout<<"Case #"<<t<<": NO"<<endl;
            return;
        }
        else
        {
            cout<<"Case #"<<t<<": YES"<<endl;
            return;
        }
    }
}
int main()
{
    int t;
    cin>>t;
   
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}