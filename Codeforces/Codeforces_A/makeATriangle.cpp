// Problem link: https://codeforces.com/contest/1064/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pashaAndPixels()
{
    int arr[3];
    for(int i=0; i<3; i++) cin>>arr[i];
    sort(arr,arr+3);
    int x = arr[0]+arr[1];
    if(x>arr[2]) cout<<0<<endl;
    else
    {
        if(x==arr[2]) cout<<1<<endl;
        else cout<<(arr[2]-x+1)<<endl;
    }
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--) pashaAndPixels();
}

