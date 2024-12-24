// Problem Link: https://codeforces.com/contest/1547/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void shortesPathWithObsticle()
{
    int a,A,b,B,f,F;
    cin>>a>>A>>b>>B>>f>>F;
    int ans =0;
    if(a==b and b==f and f==a)
    {
        if((F>B and F<A) or (F>A and F<B))
        {
            ans = abs(A-B);
            ans+=2;
        }
        else ans = abs(A-B);
    }
    else if(A==B and B==F and F==A)
    {
        if((f>b and f<a) or (f>a and f<b))
        {
            ans = abs(a-b);
            ans+=2;
        }
        else ans = abs(a-b);
    }
    else
    {
        ans = abs(A-B)+abs(a-b);
    }
    cout<<ans<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--) 
   {
        shortesPathWithObsticle();
   }
}