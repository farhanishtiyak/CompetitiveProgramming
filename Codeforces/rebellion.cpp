// Problem Link : https://codeforces.com/contest/1746/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void rebellion()
{
    int n; 
    cin>>n; 
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        
    }
    int ans =0;

    int i=0,j=n-1;
    while(i<=j)
    {
        while(arr[i]!=1) i++;
        while(arr[j]!=0)j--;
        if(i<j and arr[i]==1 and arr[j]==0)
        {
            ans++;
            swap(arr[i],arr[j]);
        }
    }

    cout<<ans<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--) rebellion();
}