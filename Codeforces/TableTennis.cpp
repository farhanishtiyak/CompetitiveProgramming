// Problem Link: https://codeforces.com/contest/879/problem/B


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
    ll k;
    cin>>k;
    if(k>n) k=n;
    deque<int> arr;
    for0(i,n)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int ans = 0;
    ll cnt = 0;
    int x = arr[0];
    arr.pop_front();
    bool flag = true;
    while(flag)
    {
        int y = arr[0];
        arr.pop_front();
        if(x>y) 
        {
            cnt++;
            arr.push_back(y);
            if(cnt==k) 
            {
                flag = false;
                ans = x;
            }
        }
        else
        {
            arr.push_back(x);
            x = y;
            cnt =1;
        }

    }

    cout<<ans<<endl;
   
}