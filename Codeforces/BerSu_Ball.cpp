// Problem Link: https://codeforces.com/problemset/problem/489/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void berSUball()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    sort(arr.begin(), arr.end());

    int m;
    cin >> m;
    vector<int> brr(m);
    for (auto &x : brr)
        cin >> x;
    sort(brr.begin(), brr.end());

    int ans = 0;

    unordered_set<int> st;
    if (m < n)
    {
        for (int i = 0; i < m; i++)
        {
            int x = brr[i];
            for (int j = 0; j < n; j++)
            {
                if (st.count(j))
                    continue;
                else
                {
                    int dif = abs(arr[j] - x);
                    if (dif <= 1)
                    {
                        st.insert(j);
                        ans++;
                        break;
                    }
                }
            }
        }
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            for (int j = 0; j < m; j++)
            {
                if (st.count(j))
                    continue;
                else
                {
                    int dif = abs(brr[j] - x);
                    if (dif <= 1)
                    {
                        ans++;
                        st.insert(j);
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        berSUball();
}
