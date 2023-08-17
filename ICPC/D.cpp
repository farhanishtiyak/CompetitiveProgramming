#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll sum = 0, a, b, c, d;
        cin >> a >> b >> c >> d;

        ll cnt = 0;
        if (a < d)
            cnt++;
        if (b < d)
            cnt++;
        if (c < d)
            cnt++;
        if (a == b and b == c and c == a)
        {
            cout << "Case " << i << ": Peaceful" << endl;
            continue;
        }
        sum = a + b + c;
        if (cnt >= 2 or sum % 3 != 0)
        {
            cout << "Case " << i << ": Fight" << endl;
            continue;
        }

        ll arr[3];
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        sort(arr, arr + 3);

        ll avg = sum / 3;

        ll diff;
        if (arr[1] < avg)
        {
            diff = avg - arr[1];
            if (diff % d == 0)
            {
                if (arr[2] - diff >= d)
                {
                    arr[2] = arr[2] - diff;
                    arr[1] = avg;
                }
            }
            else
            {
                cout << "Case " << i << ": Fight" << endl;
                continue;
            }

            ll mn = min(arr[0], arr[2]);
            ll dif = abs(mn - avg);
            if (dif % d == 0)
            {
                cout << "Case " << i << ": Peaceful" << endl;
                continue;
            }
            else
            {
                cout << "Case " << i << ": Fight" << endl;
                continue;
            }
        }
        else if (arr[1] > avg)
        {
            ll difff = arr[1] - avg;
            if (difff % d == 0)
            {
                arr[0] += difff;
                arr[1] = avg;
            }
            else
            {
                cout << "Case " << i << ": Fight" << endl;
                continue;
            }

            ll mn = min(arr[0], arr[2]);
            ll dif = abs(mn - avg);
            if (dif % d == 0)
            {
                cout << "Case " << i << ": Peaceful" << endl;
                continue;
            }
            else
            {
                cout << "Case " << i << ": Fight" << endl;
                continue;
            }
        }
        else
        {
            ll mn = min(arr[0],arr[2]);
            ll dif = abs(mn-avg);
            if(dif%d==0)
            {
                cout << "Case " << i << ": Peaceful" << endl;
            continue;
            }
            else
            {
                cout << "Case " << i << ": Fight" << endl;
            continue;
            }
        }
    }
}