
#include<bits/stdc++.h>

using namespace std;

#define  Sezar  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define  tc(t)  int t; cin >> t; while (t--)
#define  ll     long long
#define  int     long long
#define  ld     long double

void solution()
{   
    int n;
    cin>>n;
    vector<int> arr;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
        mp[x]++;
    }

    int ans = 0;
    unordered_map<int, int> occured;
    for (int i = 0; i < n; i++){
        int x = arr[i];
        int y = -x;

        occured[x]++;
        int cur = 0;
        if(x!=0 and occured.find(y)!=occured.end()){
            cur = n - (i + 1) - (mp[x] + mp[y]) + occured[x] + occured[y];
        }

        if(x==0 and occured[0]>1){
            cur = n - (i + 1) - (mp[x]) + occured[x];
        }
        int z = occured[y];

        if(x==0){
            z--;
        }
        cur *= z;


        //cout << arr[i] << "-->" << cur << endl;
        ans += cur;
    }
    cout << ans << endl;
}

int32_t main()
{
    Sezar;
    tc(t) solution();
    // solution();
}