// Problem Link: https://codeforces.com/problemset/problem/26/A


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
#define endl "\n"

bool PrimeFactorization(int n)
{
    unordered_set<int> st;
    for(int i=2; i*i<=n; i++)
    {
        while(n%i==0)
        {
            st.insert(i);
            n/=i;
        }
    }
    if(n>1) st.insert(n);
    if(st.size()==2) return true;
    else return false;
}

void almostPrime()
{
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    for(int i=2; i<=n; i++)
    {
        if(PrimeFactorization(i)) mp[i]=1;
        else mp[i] =0;
    }
    
    int ans =0;
    for(int i=2; i<=n; i++)  if(mp[i]) ans++;
        
    cout<<ans<<endl;

}


int main()
{
    fio;
    //tc(t) 
    almostPrime();
}