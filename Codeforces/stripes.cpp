// Problem link: https://codeforces.com/contest/1742/problem/C


#include <bits/stdc++.h>
using namespace std;
#define ll long long

void stripes()
{

    char arr[8][8];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++) cin>>arr[i][j];
    }
    bool flag = false;
    int cnt =0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {

            if(arr[i][j]=='R') 
            {
                cnt++;
            }
        } 
        if(cnt ==8) break;
        else cnt =0;
    }
    if(cnt ==8) cout<<"R"<<endl;
    else cout<<"B"<<endl;
 
}
int main()
{
    int t;
     cin >> t;
    while (t--)
        stripes();
}
