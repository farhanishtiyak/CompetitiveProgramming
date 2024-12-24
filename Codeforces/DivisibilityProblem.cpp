// Problem link: https://codeforces.com/contest/1328/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void divisibilityProblem()
{
    int a,b;
    cin>>a>>b;
    if(a%b==0) cout<<0<<endl;
    else 
    {
        int x = a%b;
        cout<<(b-x)<<endl;
    }
}
int main()
{
    int t=1;
    cin>>t;
   while(t--)  divisibilityProblem();
}