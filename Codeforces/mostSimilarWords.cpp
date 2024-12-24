// Problem Link: https://codeforces.com/contest/1676/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void mostSimilarWords()
{
    int n,m;
    cin>>n>>m;
    vector<string> s;
    for(int i=0; i<n; i++)
    {
        string x; 
        cin>>x;
        s.push_back(x);
    }
    int ans =INT_MAX;
    for(int i=0; i<(n-1); i++)
    {
        for(int k =(i+1); k<n; k++)
        {
            int sum =0;
            for(int j=0; j<m; j++) sum+=abs((s[i][j]) - (s[k][j]));
            ans = min(ans,sum);
        }
    }
    cout<<ans<<endl;
    
}
int main()
{
   int t;
   cin>>t;
   while(t--) mostSimilarWords();
}