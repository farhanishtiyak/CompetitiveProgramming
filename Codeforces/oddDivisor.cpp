// Problem Link: https://codeforces.com/contest/1475/problem/A

#include<bits/stdc++.h>
using namespace std;

void oddDivisor()
{
    long long int n; 
    cin>>n;
    if(n&(n-1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) oddDivisor();
}