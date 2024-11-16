#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> up, left, right, upRight;
    for (int i = 0; i < l; i++)
    {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == 'U')
            up.push_back(x);
        else
            right.push_back(x);
    }

    int ans = (r == 0) ? l + 1 : 0;

    sort(all(up)), sort(all(left)), sort(all(right)), sort(all(upRight));

    for (int i = 0; i < r; i++)
    {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == 'U')
            upRight.push_back(x);
        else
            left.push_back(x);
    }

    for (int i = 0; i < right.size(); i++)
    {
        if (i == 0)
            ans = (l + 1) * 2;
        else
            ans = ans - (l + 1) + (l + 1) * 2;
    }
    for (int i = 0; i < upRight.size(); i++)
    {
        int upore = up.size() - (upper_bound(up.begin(), up.end(), upRight[i]) - up.begin());
        int dane = right.size();
        ans += upore + dane + 1;
    }
    cout << ans << '\n';
    return 0;
}