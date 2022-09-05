// Problem link: https://codeforces.com/contest/1703/problem/B

#include<bits/stdc++.h>
using namespace std;

void icpcBallons()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_set<char>st;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(st.count(s[i])) ans++;
        else 
        {
            ans+=2;
            st.insert(s[i]);
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) icpcBallons();
}