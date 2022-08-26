#include <bits/stdc++.h>
using namespace std;

void BeautifulArray()
{
    long long int n, k, b, s;
    cin >> n >> k >> b >> s;
    long long int arr[n];

    if (s < k * b || s > ((k * b) + ((n) * (k - 1))))
    {
        cout << -1 << endl;
        return;
    }

    else
    {   s -= k * b;
        for(int i =0 ; i<n; i++) arr[i]=0;
        arr[0] = k * b;
        
        for (int i = 0; i < n; i++)
        {
            int m = min(s, (k - 1));
            s = s - m;
            arr[i] += m;
        }
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        BeautifulArray();
}