#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v;
    if (n % 2 == 0)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i & 1 == 1)
            {
                v.push_back(s[i]);
                v.push_back('-');
            }
            else
                v.push_back(s[i]);
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i!=0 && i%2==0)
            {
                v.push_back(s[i]);
                v.push_back('-');
            }
            else
                v.push_back(s[i]);
        }
    }

    for(auto val : v)
    cout<<val;
    cout<<endl;
}