// Problem link: https://codeforces.com/contest/887/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MOD (int) 1e9+7
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define tc(t) int t; cin >> t; while (t--)
#define int int
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"

void div()
{
    string s;
    cin>>s;
    int sz = s.size();
    for(int i=0; i<sz; i++)
    {
        int cnt =0;
        if(s[i]=='1')
        {
            for(int j=i+1; j<sz; j++)
            {
                if(s[j]=='0') cnt++;
            }
            if(cnt>=6) 
            {
                cout<<"yes"<<endl;
                return;
            }
        }
    }
    cout<<"no"<<endl;
}
int main()
{
    fio;
    div();
}