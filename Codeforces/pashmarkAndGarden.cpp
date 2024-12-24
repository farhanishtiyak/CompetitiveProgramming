// Problem link: https://codeforces.com/contest/459/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pashmarkAndGarden()
{
    int x1,y1,x2,y2,a,b;
    cin>>x1>>y1>>x2>>y2;
    a = max(x1,x2)-min(x1,x2);
    b = max(y1,y2)-min(y1,y2);
    if(x1==x2)  cout<<(b+x1)<<" "<<y1<<" "<<(b+x1)<<" "<<y2<<endl;
    else if(y1==y2)  cout<<x1<<" "<<(a+y1)<<" "<<x2<<" "<<(a+y1)<<endl;
    else
    {
         if(a!=b)
        {
            cout<<-1<<endl;
            return;
        }
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
    }
}
int main()
{
    int t=1;
    //cin >> t;
    while (t--) pashmarkAndGarden();
}

