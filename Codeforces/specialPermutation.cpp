// Problem Link: https://codeforces.com/contest/1454/problem/A

#include<bits/stdc++.h>
using namespace std;

void specialPermutation()
{
    int n;
    cin>>n; 
    cout<<2<<" "<<1<<" ";
    for(int i=n; i>=3; i--) cout<<i<<" ";
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) specialPermutation();
}