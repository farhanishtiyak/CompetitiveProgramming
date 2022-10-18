// Problem link: https://codeforces.com/contest/1746/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void maxima()
{
    int n,k;
    cin>>n>>k;
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        int x; 
        cin>>x;
        if(x==1) flag = true;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--) maxima();
}