// Problem Link : https://codeforces.com/problemset/problem/1688/A

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    bitset<32>b(n);
    bitset<32>check;
    
    for(int i=0; i<n; i++)
    {
        if(b[i]==1) 
        {
            check.set(i,1);
            break;
        }
    }
    if((b^check)==0)
    {
       
        for(int i=0; i<32; i++)
        if(b[i]==0 && check[i]==0) 
        {
            check[i]=1;
            break;
        }
        long long int ans = check.to_ullong();
        cout<<ans<<endl;
    }
    else{
         long long int ans = check.to_ullong();
        cout<<ans<<endl;
    }
    cout<<b<<endl<<check;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solve();
}
