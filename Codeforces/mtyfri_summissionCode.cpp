#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int n, k;
    cin >> n >> k;
    vector<int> m;
    vector<int> t;
    int tomu = 0;
    int motu = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i % 2 == 0)
            m.push_back(x);
        else
            t.push_back(x);
    }
    sort(m.begin(), m.end());
    sort(t.begin(), t.end(), greater<int>());
    while (k--)
    {
        if (*(t.end() - 1) >= *(m.end() - 1))
        {
            tomu += *(t.end() - 1);
            motu += *(m.end() - 1);
            t.pop_back();
            m.pop_back();
        }
        else
        {
            tomu += *(m.end() - 1);
            motu += *(t.end() - 1);
            t.pop_back();
            m.pop_back();
        }
    }
    for (auto it = t.begin(); it < t.end(); it++)
        tomu += *it;
    
    for (auto it = m.begin(); it < m.end(); it++)
        motu += *it;
    if (tomu > motu)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solution();
    return 0;
}