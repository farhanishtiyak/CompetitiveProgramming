#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;

    ll arr[n + 1];
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];

    if (n > m)
    {
        cout << "YES" << endl;
        return 0;
    }

    ll dp[n + 1][m];
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < m; i++)
    {
        if (i == (arr[1] % m))
            dp[1][i] = 1;
        else
            dp[1][i] = 0;
    }

    // for(ll i=0; i<m; i++) cout<<dp[1][i]<<" ";
    // cout<<endl<<endl;

    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i] % m == j)
                dp[i][j] = 1;
            if (dp[i - 1][j] == 1)
            {
                dp[i][j] = 1;
                ll sum = arr[i] + j;
                sum = sum % m;
                dp[i][sum] = 1;
            }
        }
        for (ll j = 0; j < m; j++)
        {
            if (dp[i][j] != 1)
                dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[n][0] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}