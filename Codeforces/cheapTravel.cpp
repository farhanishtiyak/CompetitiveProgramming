#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int minCost =0;
    if((b/m)<a)
    {
        int x = n/m;
        minCost+=x*b;
        x = n%m;
        minCost+=min(x*a,b);
        cout<<minCost<<endl;
    }
    else cout<<n*a<<endl;
}