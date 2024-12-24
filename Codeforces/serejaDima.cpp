// Problem Link:  https://codeforces.com/contest/381/problem/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sereja = 0, dima = 0;
    deque<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    bool serja = true;
    while (!arr.empty())
    {
        if (serja)
        {
            if (arr.front() > arr.back())
            {
                sereja += arr.front();
                arr.pop_front();
            }
            else
            {
                sereja += arr.back();
                arr.pop_back();
            }
            serja = false;
        }

        else
        {
            if (arr.front() > arr.back())
            {
                dima += arr.front();
                arr.pop_front();
            }
            else
            {
                dima += arr.back();
                arr.pop_back();
            }
            serja = true;
        }
    }
    cout << sereja << " " << dima << endl;
}