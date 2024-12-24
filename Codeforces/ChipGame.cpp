#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;

    int e, o;
    cin >> n >> m;
    if (n == 1 & m == 1)
    {
        cout << "Tonya" << endl;
        return;
    }
    else
    {
        if ((n % 2 != 0 && m % 2 != 0) || (n % 2 == 0 && m % 2 == 0))
        {
            cout << "Tonya" << endl;
        }
        else
        {
            cout << "Burenka" << endl;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}