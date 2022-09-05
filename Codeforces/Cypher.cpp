// Problem Link: https://codeforces.com/contest/1703/problem/C

#include<bits/stdc++.h>
using namespace std;

void cypher()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++)
    {
        int l;
        cin>>l;
        string x;
        cin>>x;
        for(int j=0; j<l; j++)
        {
            if(x[j]=='D')
            {
                if(arr[i]==9) arr[i]=0;
                else arr[i]=arr[i]+1;
            }
            else
            {
                if(arr[i]==0) arr[i]=9;
                else arr[i]=arr[i]-1;
            }
        }
    }
    for(auto val : arr)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
}
int main()
{
    int t;
    cin>>t;
    while(t--) cypher();

}