#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int a,b,c,d;
        unsigned long long int x;
        unsigned long long int y;
        cin>>a>>b>>c>>d;
        long long int mini = min(b,d);
        b-=mini;
        d-=mini;
        for(int i=0; i<b; i++) a*=10;
        for(int i=0; i<d; i++) c*=10;

        if(x>y) cout<<">"<<endl;
        else if(x<y)cout<<"<"<<endl;
        else cout<<"="<<endl;
    }
}