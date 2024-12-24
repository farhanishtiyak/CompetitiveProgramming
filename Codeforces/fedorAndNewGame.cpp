// Problem Link: https://codeforces.com/problemset/status?my=on

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fedorAndNewGame()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr;
    int ans = 0;
    for(int i=0; i<=m; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    bitset<32> last(arr[m]);
    for(int i=0; i<m; i++)
    {
        int cnt =0;
        bitset<32> check(arr[i]);
        for(int j=0; j<=n; j++)
        {
            if(check[j]!=last[j]) cnt++;
        }
        if(cnt<=k) ans++;
    }

    cout<<ans<<endl;

}
int main()
{
    int t =1;
    //cin >> t;
    while (t--) fedorAndNewGame();
}
