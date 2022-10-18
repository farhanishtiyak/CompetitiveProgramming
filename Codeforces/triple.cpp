// Problem link: https://codeforces.com/problemset/problem/1669/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void triple()
{
    
    int n;
    cin>>n;
    int ans =-1;
    bool flag = false;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) 
    {
        int x;
        cin>>x;
        mp[x]++;
        if(mp[x]>=3)
        {
            if(!flag) ans = x;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    cin>>t;
   while(t--) 
   {
        triple();
   }
}