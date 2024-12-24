#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;
    s += s;

    int n = s.length();
    vector<int> parent(n + 1, -1), left(n + 1, -1), right(n + 1, -1);

    int node = 1, cur = 1;
    for (char &ch : s)
    {
        if (ch == 'L')
        {
            if (left[cur] != -1)
            {
                cur = left[cur];
                continue;
            }
            left[cur] = node + 1;
            parent[node + 1] = cur;
            node++;
            cur = node;
        }
        else if (ch == 'R')
        {
            if (right[cur] != -1)
            {
                cur = right[cur];
                continue;
            }
            right[cur] = node + 1;
            parent[node + 1] = cur;
            node++;
            cur = node;
        }
        else
        {
            if (parent[cur] != -1)
            {
                cur = parent[cur];
                continue;
            }
            parent[cur] = node + 1;
            left[node + 1] = cur;
            node++;
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (left[i] == -1)
        {
            left[i] = node + 1;
            node++;
            flag = false;
            break;
        }
    }

    if (flag)
    {
        for (int i = 1; i <= n; i++)
        {
            if (right[i] == -1)
            {
                right[i] = node + 1;
                node++;
                flag = false;
                break;
            }
        }
    }

    cout << node << ' ' << 1 << ' ' << node << '\n';

    for (int i = 1; i <= node; i++)
    {
        cout << (left[i] == -1 ? 0 : left[i]) << ' ';
        cout << (right[i] == -1 ? 0 : right[i]) << "\n";
    }

    return 0;
}