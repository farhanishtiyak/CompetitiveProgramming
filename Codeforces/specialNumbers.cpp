// Problem link: https://codeforces.com/problemset/problem/1594/B

#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int binPowIter(int n,int p)
{
    int ans=1;
    while(p)
    {
        if(p&1) ans = (ans*1LL*n)%M;
        n=(n*1LL*n)%M;
        p>>=1;
    }
    return ans;
}

void specialNumbers()
{
    long long int ans=0;
    int n,k;
    cin>>n>>k;
    for(int i=0; i<32; i++)
    {
        if((1<<i)&k)
        {
            ans=(ans+(binPowIter(n,i)))%M;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) specialNumbers();
}