// Problem Link: https://codeforces.com/contest/1733/problem/B


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
#define endl "\n"

void ruleOfLeague()
{
    int n,x,y;
    cin>>n>>x>>y;
    int mini = min(x,y);
    int maxi = max(x,y);
    int check = 1;
    vector<int> ans; 
    ans.pb(1);
    bool flag = true;
    if(mini>0)
    {
        cout<<-1<<endl;
        return;
    }
    if(mini==0 and maxi ==0)
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        while(flag)
        {
            if(check<n) 
            {
                check+=maxi;
                if(check<n) ans.pb((check+1));
            }
            else flag = false;
        }

        if(check==n) 
        {
            for(auto it=ans.begin(); it!=ans.end(); it++)
                for(int i=1; i<=maxi; i++)
                    cout<<*it<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}

int main()
{
    fio;
    tc(t) ruleOfLeague();
}