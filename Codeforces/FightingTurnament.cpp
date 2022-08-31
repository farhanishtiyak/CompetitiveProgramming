#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    vector<int> v;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    while (q--)
    {
        int p, k, cnt = 0;
        cin >> p >> k;
        int st = v[p - 1];
        while (k--)
        {
            if (v[0] > v[1])
            {
                if (v[0] == st)
                {
                    cnt++;
                    int x = v[1];
                    v.erase(v.begin() + 1);
                    v.push_back(x);
                }
                else
                {
                    int x = v[1];
                    v.erase(v.begin() + 1);
                    v.push_back(x);
                }
            }

            else
            {
                if (v[1] == st)
                {
                    cnt++;
                    int x = v[0];
                    v.erase(v.begin());
                    v.push_back(x);
                }
                else
                {
                    int x = v[0];
                    v.erase(v.begin());
                    v.push_back(x);
                }
            }

            
        }
        cout << cnt << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}