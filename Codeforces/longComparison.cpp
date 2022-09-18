// Problem Link: https://codeforces.com/problemset/problem/1613/A

#include<bits/stdc++.h>
using namespace std;

void longComparison()
{
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        double ans = a/b;
        ans = ans*pow(10,(a-b));
        if(ans>1) cout<<">"<<endl;
        else if(ans<1) cout<<"<"<<endl;
        else cout<<"="<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        longComparison();
    }
}