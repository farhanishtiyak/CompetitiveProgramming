// Problem link: https://codeforces.com/problemset/problem/492/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void vanyaAndLanterns()
{
    int n,l;
    cin>>n>>l;
    int arr[n];
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) 
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    
    sort(arr,arr+n);
    int maxi =INT_MIN;
    for(int i=0; i<(n-1); i++)
    {
        int x = arr[i+1]-arr[i];
        maxi = max(maxi, x);
    }

    double diff = maxi/2.0;
    if(!mp[0]) 
    {
        if(arr[0]>diff) diff = arr[0];
    }
    if(!mp[l]) 
    {
        double  x = l - arr[n-1];
        if(x>diff) diff=x;
        
    }
    printf("%0.10f\n",diff ); 

}
int main()
{
    vanyaAndLanterns();
}