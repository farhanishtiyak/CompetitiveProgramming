// Problem link: https://codeforces.com/contest/1535/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void fairPlayoff()
{
    int arr[4];
    for(int i=0; i<4; i++) cin>>arr[i];
    int first = max(arr[0],arr[1]);
    int second = max(arr[2],arr[3]);
    sort(arr,arr+4);
    if((second==arr[2] or second == arr[3]) and (first==arr[2] or first == arr[3]))
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
}
int main()
{
    int t=1;
    cin>>t;
   while(t--)  fairPlayoff();
}