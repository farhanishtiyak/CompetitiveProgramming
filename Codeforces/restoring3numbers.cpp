// Problem link: https://codeforces.com/contest/1154/problem/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4];
    int mx =0;
    for(int i=0; i<4; i++)
    {
        cin>>arr[i];
        if(arr[i]>mx) mx = arr[i];
    }
    for(int i=0; i<4; i++)
    {
        if(arr[i]==mx) continue;
        else cout<<(mx-arr[i])<<" ";
    }
    cout<<endl;
}