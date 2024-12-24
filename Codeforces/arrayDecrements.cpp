// Problem link: https://codeforces.com/contest/1690/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void arrayDecrements()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    if(a[0]<b[0])
    {
        cout<<"NO"<<endl;
        return;
    }
    int diff = a[0]-b[0];

    for(int i=0; i<n; i++)
    {
        diff = max(diff,a[i]-b[i]);
    }

    for(int i=0; i<n; i++)
    {
        if(a[i]<b[i])
        {
            cout<<"NO"<<endl;
            return;
        }

        if(b[i]!=0)
        {
            int x = a[i]-b[i];
            if(x==diff) continue;
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;

}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  arrayDecrements();
}