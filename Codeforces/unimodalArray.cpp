// Problem Link: https://codeforces.com/contest/831/problem/A


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
    vi arr;
    for0(i,n)
    {
        int x;
        cin>>x;
        arr.pb(x);
    }
    if(n==1)
    {
        cout<<"YES"<<endl;
        exit(0);
    }

    bool flag = true;
    bool greater = true;
    int ind = 0;

    if(arr[1]>arr[0]) greater = true;
    else greater =false;

    for(int i=1; i<n; i++)
    {
        if(greater)
        {
            if(arr[i]>arr[i-1])  continue;
            else if(arr[i]==arr[i-1])
            {
                greater = false;
                ind = i;
            }
            else 
            {
                greater = false;
            }
        }
        
        else
        {
            if(arr[i]>arr[i-1] )
            {
                flag = false;
                break;
            }
            else if(arr[i]==arr[i-1] and arr[i]!=arr[ind]) 
            {
                flag = false;
                break;
            }
            else continue;
        }
        
    }


    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   
}