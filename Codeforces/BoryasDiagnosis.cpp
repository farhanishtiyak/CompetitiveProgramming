// Problem link : https://codeforces.com/contest/879/problem/A


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


int main()
{
    fio;
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    int ans =0;
    for0(i,n)
    {
        int x,y;
        cin>>x>>y;
        arr.pb(make_pair(x,y));
    }
     
    for0(i,n)
    {
        bool flag = true;
        while(flag)
        {
            if(arr[i].first>ans)
            {
                ans = arr[i].first;
                flag = false;
            }
            else
            {
                arr[i].first+=arr[i].second;
            }
        }
    }

    cout<<ans<<endl;
}