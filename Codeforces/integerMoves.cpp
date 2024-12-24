// Problem link: https://codeforces.com/contest/1657/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void integerMoves()
{
    int x,y;
    cin>>x>>y;
    float num = sqrt((x*x)+(y*y));
    int n = (int)num;
    if(x==0 and y==0) cout<<0<<endl;
    else if(n==num) cout<<1<<endl;
    else cout<<2<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  integerMoves();
}