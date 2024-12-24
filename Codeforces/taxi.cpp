#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int cnt = 0;

    if (mp[3] >= mp[1])
    {
        cnt += mp[1];
        mp[3] = (mp[3] - mp[1]);
        mp[1] = 0;

        if (mp[2] > 0)
        {
            int two;
            if (mp[2] & 1 == 1)
            {
                two = mp[2] / 2 + 1;
                cnt += two;
            }

            else
            {
                two = mp[2] / 2;
                cnt += two;
            }
        }
        if (mp[3] > 0)
            cnt += mp[3];
    }
    else
    {
        cnt += mp[3];
        mp[1] -= mp[3];
        mp[3] = 0;
        if (mp[2] > 0)
        {
            int two;
            if (mp[2] & 1 == 1)
            {
                two = mp[2] / 2 + 1;
                cnt += two;
                if(mp[1]==1&&mp[1]!=0)
                {
                    mp[1]--;
                }
                else mp[1]-=2;
            }

            else
            {
                two = mp[2] / 2;
                cnt += two;
            }
        }

        if (mp[1] > 0)
            {
                if(mp[1]%4==0) 
                {
                    int x = mp[1]/4;
                    cnt+=x;
                }
                else
                {
                    int x = (mp[1]/4)+1;
                    cnt+=x;
                }
            }
    }
    int ans = mp[4] + cnt;
    cout << ans << endl;
}