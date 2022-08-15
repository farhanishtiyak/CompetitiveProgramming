#include <bits/stdc++.h>
using namespace std;

int solution()
{
    int n, k;
    int cnt = 0;
    cin >> n;
    cin >> k;

    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    if (k == n)
    {
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        if(arr[i]>k) cnt++;
        else
            continue;
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
       cout<< solution()<<endl;
}