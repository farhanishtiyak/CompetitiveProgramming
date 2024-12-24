#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    int ct=0;
    for(auto i=0; i<n; i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    sum=sum/2;
    int sum2=0;
    sort(arr,arr+n,greater<int>());
    for(auto i=0; i<n; i++)
    {
        sum2+=arr[i];
        ct++;
        if(sum2>sum) 
        {
            cout<<ct<<endl;
            break;
        }
    }
}