
#include <bits/stdc++.h>
using namespace std;
#define MOD (int)1e9 + 7
#define all(a) a.begin(), a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define tc(t) int t;   cin >> t; while (t--)
#define int int
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"

void decodeString()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    unordered_map<int, char> mp;
    char ch = 'a';
    for (int i = 1; i <= 26; i++)
    {
        mp[i] = ch++;
    }
    bool flag = true;
    int i = 0;
    while (flag)
    {
        char c = s[i];
        string r(1, c);
        c = s[i + 1];
        string rr(1, c);
        string rrr = r+rr;
        int num = stoi(rrr);
        int x = i+2;
        if (x<n and s[x]=='0')
        {
            v.push_back(num);
            i=i+3;
        }
        else
        {
            int num = stoi(r);
            v.pb(num);
            i++;
        }
        if(i==n)
        {
            flag = false;
        }

    }

    for(auto val : v)
    {
        cout<<mp[val];
    }
    cout<<endl;
}
int main()
{
    fio;
    tc(t) decodeString();
}