#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, i, sum = 0;
    cin >> a >> b;
    for (i = 1; i < k; i++)
    {
        sum =sum+ i;
        if ((n - sum) <= i)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}