// Problem link: https://codeforces.com/contest/1754/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void kevinAndPermutation()
{
    int n;
    cin>>n;
    int num = n/2;

    if(n&1)
    {
        cout<<(num+1+num)<<" ";
        for(int i=1; i<(num+1); i++) cout<<(i+num)<<" "<<i<<" ";
            cout<<endl;
    }

    else
    {
        for(int i=1; i<=num; i++)  cout<<(i+num)<<" "<<i<<" ";
            cout<<endl;
    }
}

int main()
{
    int t=1;
    cin>>t;
    while(t--) kevinAndPermutation();
}