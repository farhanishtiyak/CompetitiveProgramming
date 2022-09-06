// Problem Link: https://codeforces.com/contest/339/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<long long int>arr;
    for(int i=0; i<m; i++)
    {
        long long int x;
        cin>>x;
        arr.push_back(x);
    }
    int myPos=1;
    long long int ans =0;
    for(int i=0; i<m; i++)
    {
        if(arr[i]<myPos)
        {
            long long int start = (n-myPos)+1;
            long long int distance = arr[i]-1;
            ans+=(start+distance);
            myPos=arr[i];
        }
        else
        {
            ans+=(arr[i]-myPos);
            myPos=arr[i];
        }
    }
    cout<<ans<<endl;
}