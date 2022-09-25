// Problem link: https://codeforces.com/contest/1697/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void parkwayWalk()
{
    int benches, energy;
    cin>>benches>>energy;
    int sum =0;
    for(int i=0; i<benches; i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    if(sum>energy) cout<<(sum-energy)<<endl;
    else cout<<0<<endl;
}
int main()
{
    int t ;
    cin >> t;
    while (t--) parkwayWalk();
}
