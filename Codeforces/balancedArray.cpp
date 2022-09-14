// Problem Link: https://codeforces.com/contest/1343/problem/B


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

void balancedArray()
{
    int n;
    cin>>n;
    if((n>>1)&1)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        int j = 2;
        for(int i=1; i<=(n>>1); i++) 
        {
            cout<<j<<" ";
            j+=2;
        }

        j=1;

        for(int i=1; i<(n>>1); i++) 
        {
            cout<<j<<" ";
            j+=2;
        }

        int last = j+(n>>1);
        cout<<last<<endl;
    } 

}
int main()
{
    fio;
    tc(t) balancedArray();
}