#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,b;
    cin>>l>>b;
    int y=0;
    while((l-b)<=0)
    {
        l=3*l;
        b=b*2;
        y++;
    }
    cout<<y<<endl;
}