// Problem link: https://codeforces.com/problemset/problem/1472/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void fairDivision()
{
    int n;
    cin>>n;
    int one =0, two =0; 
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x==1) one++;
        else two++;
    }
    if(one&1) cout<<"NO"<<endl;
    else if(two&1 and one==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main()
{
    int t=1;
    cin>>t;
   while(t--)  fairDivision();
}