// Problem link: https://codeforces.com/contest/1681/problem/B

#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int n;
    cin >> n;
    vector<int> dq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int m;
    cin >> m;
    int mx = 1;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (mx + x > n)
        {
            mx = 0 + x - n + mx;
        }
        else
            mx += x;
    }
    cout<<dq[mx-1]<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solution();
}