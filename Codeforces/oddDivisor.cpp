// Problem Link: 

#include<bits/stdc++.h>
using namespace std;

void oddDivisor()
{
    int n; 
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