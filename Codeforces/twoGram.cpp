// Problem Link: https://codeforces.com/contest/977/problem/B


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

void TwoGram()
{
    int n; 
    cin>>n;
    string s;
    cin>>s;
    int mx = 0;
    unordered_map<string,int> mp;
    for(int i=0; i<n-1; i++)
    {
        int cnt =0;
        string one = "";
        one=one+s[i];
        one=one+s[i+1];

        for(int j=i; j<n-1; j++)
        {
            string two = "";
            two=two+s[j];
            two=two+s[j+1];
            if(one==two) 
            {
                cnt++;
            }
        }
        int maxi = max(mp[one],cnt);
        mp[one] = maxi;
        mx = max(mx,cnt);
    }
    for(auto str=mp.begin(); str!=mp.end(); str++)
    {
        if(str->second == mx) 
        {
            cout<<str->first<<endl;
            break;
        }
    }
}

int main()
{
    fio;
    //tc(t) 
    TwoGram();
}