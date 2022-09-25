// https://codeforces.com/contest/1730/problem/C

//  Do This Question Again

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        char c='9';
        for(int i=s.size()-1; i>=0; i--)
        {
            c=min(c,s[i]);
            s[i]+=( s[i]!='9' and c<s[i]);
        }

        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
}