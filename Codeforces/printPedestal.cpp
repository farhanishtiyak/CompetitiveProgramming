// Problem link: https://codeforces.com/contest/1690/problem/A


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printPedestal()
{
    int n;
    cin>>n;
    if(n==7)
    {
        cout<<2<<" "<<4<<" "<<1<<endl;
        return;
    }
    if(n%3==2)
    {
        int ans = n/3;
        cout<<(ans+1)<<" "<<(ans+2)<<" "<<(ans-1)<<endl;
    }
    else if(n%3==1)
    {
        int ans = n/3;
        cout<<ans+1<<" "<<(ans+2)<<" "<<(ans-2)<<endl;
    }
    else
    {
        int ans = n/3;
        cout<<ans<<" "<<(ans+1)<<" "<<(ans-1)<<endl;
    }

}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  printPedestal();
}