// Problem link: https://codeforces.com/contest/1749/problem/B


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void DeathsBlessing()
{
    int n;
    cin>>n;
    ll arr[n];
    ll sum = 0;
    for(int i=0; i<n; i++) 
    {
        ll x;
        cin>>x;
        sum+=x;
    }
    ll maxi = INT_MIN;
    int index = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]>maxi) 
        {
            maxi = arr[i];
            index = i;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(i==index) continue;
        else sum+=arr[i];
    }

    cout<<sum<<endl;

}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  DeathsBlessing();
}