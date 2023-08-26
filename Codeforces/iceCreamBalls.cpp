#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s;
	//cin >> s;
	int n;
	//cin >> n;
	

	while (cin >> s >> n) {
        int l = s.size();
		for (int i = l - 1; i >= 0; i--)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				int x = n % 10;
				n /= 10;
				int v = (s[i] - '0') + x;
				n += (v / 10);
				v = v % 10;
				s[i] = ('0' + v);
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				int x = n % 26;
				n /= 26;
				int v = (s[i] - 'a') + x;
				n += (v / 26);
				v = (v % 26);
				s[i] = ('a' + v);
			}
			else
			{
				int x = n % 26;
				n /= 26;
				int v = (s[i] - 'A') + x;
				n += (v / 26);
				v = (v % 26);
				s[i] = ('A' + v);
			}
			if (i == 0 && n > 0)
			{
				if (s[0] >= 'A' && s[0] <= 'Z')
					cout << char('A' + n - 1);
				else if (s[i] >= 'a' && s[i] <= 'z')
					cout << char('a' + n - 1);
				else
				{
					while (n > 0)
					{
						if (n <= 9)
						{
							cout << n;
							break;
						}
						else
						{
							cout << 9;
							n -= 9;
						}
					}
				}
			}
		}
		cout << s << endl;
	}
}

int32_t main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}