// Problem link: https://codeforces.com/contest/451/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void SortTheArray()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    if(is_sorted(arr,arr+n))
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
        return;
    }

    int ind =0, index = (n-1);
    for(int i=0;i<(n-1);i++)
    {
        if(arr[i]>arr[i+1]) 
        {
            ind = i;
            break;
        }
    }
    for(int i=(n-1); i>=1; i--)
    {
        if(arr[i]<arr[i-1]) 
        {
            index = i+1;
            break;
        }
    }
    reverse(arr+ind, arr+index);
    if(is_sorted(arr,arr+n))
    {
        cout<<"yes"<<endl;
        cout<<ind+1<<" "<<index<<endl;
    }
    else cout<<"no"<<endl;
}

int main()
{
    int t=1;
    //cin>>t;
    while(t--) SortTheArray();
}