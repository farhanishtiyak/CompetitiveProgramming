
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void selectThreeSticks()
{
    int n; 
    cin>>n;
    vector<int> arr;
    map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int ans =INT_MAX;

    for(int i=1; i<n-1; i++)
    {
        int x = arr[i+1]-arr[i];
        int y = arr[i]-arr[i-1];
        x = x+y;
        ans = min(ans,x);

    }
    cout<<ans<<endl;
}
int main()
{
    int t;
     cin >> t;
    while (t--)
        selectThreeSticks();
}
