// Problem link: https://codeforces.com/problemset/problem/508/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pashaAndPixels()
{
    int n,m,k,move=0;
    cin>>n>>m>>k;
    int arr[n+5][m+5];
    for(int i=0; i<n+5; i++)
    {
        for(int j=0; j<m+5; j++) arr[i][j]=0;
    }

    for(int i=1; i<=k; i++)
    {
        int x,y;
        cin>>x>>y;
        arr[x][y] = 1;
        if(move==0)
        {
            if(arr[x][y+1]+arr[x-1][y+1]+arr[x-1][y]==3) move = i;
            if(arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y]==3) move = i;
            if(arr[x][y-1]+arr[x-1][y-1]+arr[x-1][y]==3) move = i;
            if(arr[x][y-1]+arr[x+1][y-1]+arr[x+1][y]==3) move = i;
        }
    }
    cout<<move<<endl;
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--) pashaAndPixels();
}

