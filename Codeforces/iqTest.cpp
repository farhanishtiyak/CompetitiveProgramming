// Problem link: 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void IQtest()
{
    int arr[5][5] = {1};
    for(int i=0;i<=4; i++)
    {
        for(int j=0; j<=4; j++)
        {
            arr[i][j]=1;
        }
    }

    bool flag = false;
    for(int i=1;i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            char ch;
            cin>>ch;
            if(ch=='#') arr[i][j]==1;
            else arr[i][j]=2;
            if(i>1 and j>1 and !flag)
            {
                int x = arr[i][j-1]+arr[i-1][j]+arr[i-1][j-1]+arr[i][j];
                if(x==4 or x==5 or x==7 or x==8) flag = true;
            }
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--) IQtest();
}

