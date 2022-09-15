// Prblem link : https://codeforces.com/contest/1692/problem/A

#include<bits/stdc++.h>
using namespace std;

void marathon()
{
    int a;
    cin>>a;
    int ans =0;
    for(int i=1; i<4; i++ )
    {
        int x;
        cin>>x;
        if(x>a) ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) marathon();
}