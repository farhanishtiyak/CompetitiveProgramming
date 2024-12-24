#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int a, b, c, d, ans, x;
    cin >> a >> b >> c >> d;
    int A = a, B = a;
    ans = a;
    bool flag = true;
    while (flag)
    {
        if (A < B)
        {
            if (b > 0)
            {
                x = min(B, b);
                A += x;
                B -= x;
                b -= x;
                ans += x;
            }
            else
            {
                x = min(A, c);
                A -= x;
                B += x;
                c -= x;
                ans += x;
            }
        }
        else
        {
            if (c > 0)
            {
                x = min(A, c);
                A -= x;
                B += x;
                c -= x;
                ans += x;
            }
            else
            {
                x = min(B, b);
                A += x;
                B -= x;
                b -= x;
                ans += x;
            }
        }

        if ((b == 0 and A == 0) or (B == 0 and c == 0) or (b == 0 and c == 0) or (A == 0 and B == 0))
            flag = false;
        //cout << b << " " << c << "    " << A << " " << B << endl;
    }
    x = min(A, B);
    x++;
    x = min(x, d);
    ans += x;
    cout << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}