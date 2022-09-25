// Problem Link: https://codeforces.com/problemset/problem/749/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void BatchGoldProblem()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<(n/2)<<endl;
        for(int i=1 ; i<=(n/2)-1; i++)
        {
            cout<<2<<" ";
        }
        cout<<3<<endl;
    }

    else
    {
        cout<<(n/2)<<endl;
        for(int i=1 ; i<=(n/2); i++)
        {
            if(i==(n/2)) cout<<2<<endl;
            else  cout<<2<<" ";
        }
    }
}
int main()
{
    int t =1;
    //cin >> t;
    while (t--)  BatchGoldProblem();
}
