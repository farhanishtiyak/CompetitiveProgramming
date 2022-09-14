// Problem link: https://codeforces.com/contest/894/problem/A

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

//          Brute Force Method           
int main()
{
    fio;
    string s;
    cin>>s;
    int size = s.size();
    int ans =0;
    for(int i=0; i<size; i++)
    {
        if(s[i]=='Q')
        {
            for(int j = i+1; j<size; j++)
            {
                if(s[j]=='A')
                {
                    for(int k = j+1; k<size; k++)
                    {
                        if(s[k]=='Q') ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}