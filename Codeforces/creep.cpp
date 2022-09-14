// Problem Link: https://codeforces.com/problemset/problem/1694/A

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

void creep()
{
    int a,b;
    cin>>a>>b;
    bool flag = true;
    while(a or b)
    {
        if(flag)
        {
            if(a)
            {
                cout<<0;
                a--;
            }
            else
            {
                cout<<1;
                b--;
            }
        }
        else
        {
            if(b)
            {
                cout<<1;
                b--;
            }
            else 
            {
                cout<<0;
                a--;
            }
        }
        flag^=true;
    }
    cout<<endl;
}
int main()
{
    fio;
    tc(t) creep();
}