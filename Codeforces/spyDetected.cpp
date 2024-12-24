// Problem Link: https://codeforces.com/contest/1512/problem/A


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

void spyDetected()
{
    int n; cin>>n;
    unordered_map<int,pair<int,int>> mp;
    for1(i,n)
    {
        int x; 
        cin>>x;
        mp[x].first++;
        mp[x].second = i;
    }
    for(auto val = mp.begin(); val !=mp.end(); val++)
    {
        if(val->second.first ==1) 
        {
            cout<<val->second.second<<endl;
            break;
        } 
    }
}
int main()
{
    fio;
    tc(t) spyDetected();
}