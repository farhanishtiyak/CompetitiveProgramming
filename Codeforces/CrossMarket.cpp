#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int n, m;
    cin >> n;
    cin >> m;
    if (n == 1 && m == 1)
    {
        cout << 0 << endl;
        return;
    }

    if (n == 1)
    {
        cout << m << endl;
        return;
    }
    if (m == 1)
    {
        cout << n << endl;
        return;
    }

    int ans;
    if (n < m)
    {
        ans = (m - 1) + ((n - 1) * 2) + 1;
        cout << ans << endl;
        return;
    }
    if (m < n)
    {
        ans = (n - 1) + ((m - 1) * 2) + 1;
        cout << ans << endl;
        return;
    }

    if (m == n)
    {
        ans = (n * 3) - 2;
        cout << ans << endl;
        return;
    }
}
int main()
{
    int t;
    cin >> t;

    while (t--)
        solution();
    /*
      clock_t start,End;
      start = clock();
       while(t--)
       solution();
       End = clock();

       double duration = double(End-start)/double(CLOCKS_PER_SEC);
       cout << "\nTime taken by the program is : " << fixed
            << duration << setprecision(8)<<" Seconds"<<endl;
            */
    return 0;
}