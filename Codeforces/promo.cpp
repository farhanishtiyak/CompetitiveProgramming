// Problem link: https://codeforces.com/contest/1697/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//    Brute Force Approach

void promo()
{
    int n, q;
    cin>>n>>q;
    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> ans;
    for(int i=0; i<q; i++)
    {
        int sum =0;
        set<int> st;
        int x,y;
        cin>>x>>y;
        for(int j=0; j<x; j++) 
        {
            st.insert(arr[j]);
        }
        int k=0;
        for(auto it : st)
        {
            sum+=it; 
            k++;
            if(k==y) break;
        }
        ans.push_back(sum);

    }
    for(auto value : ans) cout<<value<<endl;
}

//     Optimal Approach using Prefix sum Technique

void Promo_OptimalApproach()
{
    int n;
    cin>>n; 
    int q;
    cin>>q;

    vector<int> arr(n);
    for(auto &x : arr) cin>>x;

    sort(arr.begin(), arr.end());
    
    vector<ll> PrefixSum(n+1);
    for(int i=0; i<n; i++) PrefixSum[i+1] = PrefixSum[i]+0ll+arr[i];

    for(int i= 0; i<q; i++)
    {
        int x,y;
        cin>>x>>y;
        ll ans = PrefixSum[n-(x-y)] - PrefixSum[n-x];
        cout<<ans<<endl;
    }

}
int main()
{
    int t=1;
    //cin >> t;
    while (t--) Promo_OptimalApproach();
}
