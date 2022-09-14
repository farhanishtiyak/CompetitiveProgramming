// Problem link: https://codeforces.com/contest/892/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MOD (int) 1e9+7
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define tc(t) int t; cin >> t; while (t--)
#define int int
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"


int main()
{
    fio;
    int n;
    cin>>n;
    int arr[n];
    int brr[n];
    ll sum =0;
    int indexofMax = 0;
    int Firstmax = INT_MIN;
    int secondMax INT_MIN;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>brr[i];
        if(brr[i]>Firstmax) 
        {
            Firstmax = brr[i];
            indexofMax = i;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(i!=indexofMax)
        {
            if(brr[i]>secondMax) secondMax = brr[i]; 
        }
    }
    
    ll capability = Firstmax + 0LL + secondMax;
    //cout<<"sum : "<<sum<<endl;
    //cout<<"Capability : "<< capability<<endl;
    if(sum<=capability) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

}