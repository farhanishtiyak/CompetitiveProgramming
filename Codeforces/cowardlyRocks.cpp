// Problem link: https://codeforces.com/contest/1749/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void cowardlyRocks()
{
    int n,m;
    cin>>n>>m;
    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        arr[--x][--y]=1;
    }
    if(m<n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    int t=1;
    cin>>t;
   while(t--)  cowardlyRocks();
}