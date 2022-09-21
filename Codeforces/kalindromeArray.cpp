// Problem Link: https://codeforces.com/contest/1610/problem/B

#include <bits/stdc++.h>
using namespace std;

bool pailndrome(vector<long long> &v, long long ch,long long n)
{
    vector<long long> arr;
    for(long long  i=0; i<n; i++)
    {
        if(v[i]!=ch) arr.push_back(v[i]);
    }

    long long num = arr.size();

    for(long long i=0; i<=num/2; i++)
    {
        if(arr[i]!=arr[num-i-1])
        {
            return false;
        }
    }

    return true;
}

void KalindromeArray()
{
    long long int n;
    cin>>n;
    vector<long long int> v;
    for(long long i=0; i<n; i++)
    {
        long long  x;
        cin>>x;
        v.push_back(x);
    }

    if(n==1 or n==2)
    {
        cout<<"YES"<<endl;
        return;
    }

    bool flag = false;

    for(long long i=0; i<=n/2; i++)
    {
        if(i==(n/2)) flag = true;

        if(v[i]!=v[n-i-1])
        {
            if(pailndrome(v,v[i],n))
            {
                cout<<"YES"<<endl;
                return;
            }
            else if(pailndrome(v,v[n-i-1],n))
            {
                cout<<"YES"<<endl;
                return;
            }

            else 
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int main()
{
    int t;
    cin >> t;
    while (t--) KalindromeArray();
}
