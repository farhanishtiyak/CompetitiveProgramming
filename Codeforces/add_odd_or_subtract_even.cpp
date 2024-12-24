// Problem Link: https://codeforces.com/problemset/problem/1311/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void addODDorSubtractEven()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }

    else if((a%2)==0 and (b%2)==1)
    {
        if(b>a)
        {
            cout<<1<<endl;
            return;
        }
        else
        {
            cout<<2<<endl;
            return;
        }
    }

    else if((a%2)==1 and (b%2)==1)
    {
        if(a>b)
        {
            cout<<1<<endl;
            return;
        }
        else
        {
            cout<<2<<endl;
            return;
        }
    }

    else if((a%2)==1 and (b%2)==0)
    {
        if(a>b)
        {
            cout<<2<<endl;
            return;
        }
        else
        {
            cout<<1<<endl;
            return;
        }
    }

    else 
    {
        if(a<b)
        {
            cout<<2<<endl;
            return;
        }
        else
        {
            cout<<1<<endl;
            return;
        }
    }


}
int main()
{
    int t ;
    cin >> t;
    while (t--)  addODDorSubtractEven();
}


