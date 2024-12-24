#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int>vec;

    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=2; i<=n; i+=2)
    {

        if((((i-1)+k)*i )% 4==0)
        {
            vec.push_back(i-1);
            vec.push_back(i);
            cnt++;
            continue;
        }
        else if(((i+k)*(i-1))%4 ==0)
        {
            vec.push_back(i);
            vec.push_back(i-1);
            cnt++;
            continue;
        }
        else
        {
           cout<<"NO"<<endl;
           return;
        }
    }

    if(cnt == (n/2))
    {
        cout<<"YES"<<endl;
    }
    int x = vec.size();
    for(auto it =0; it<x; it++)
    {
        cout<<vec[it]<<" ";
        if(it&1) cout<<endl;

    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}