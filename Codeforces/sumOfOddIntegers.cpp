// problem link: https://codeforces.com/contest/1327/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sumOfOddIntegers()
{
    ll n,k;
    cin>>n>>k;
    if(k&1 and (n%2==0))
    {
        cout<<"NO"<<endl;
        return;
    }
    if((k%2==0) and (n&1))
    {
        cout<<"NO"<<endl;
        return;
    }
    ll sum = k*k;
    if(n>=sum) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--) sumOfOddIntegers();
}