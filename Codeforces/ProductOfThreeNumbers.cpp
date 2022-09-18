// Problem Link : https://codeforces.com/problemset/problem/1294/C

#include<bits/stdc++.h>
using namespace std;

void productOfThreeNumbers()
{
    int n;
    cin>>n;
    int num = n;
    int a=n,b=n,c=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            a=i;
            break;
        }
    }

    n = n/a;

    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(i!=a)  b = min(b,i);
        }

        if((n/i)!=i)
        {
            if((n/i)!=a) b = min(b,(n/i));
        }
    }

    c = n/b;

    if((a*b*c)==num and a>1 and b>1 and c>1 and a!=b and a !=c and b!=a and b !=c)
    {
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }

    else cout<<"NO"<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        productOfThreeNumbers();
    }
}