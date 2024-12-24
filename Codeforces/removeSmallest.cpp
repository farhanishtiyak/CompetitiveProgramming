// Problem Link: https://codeforces.com/contest/1399/problem/A

#include<bits/stdc++.h>
using namespace std;

void solution()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    bool flag = true;
    sort(arr.begin(),arr.end());
    for(int i=0; i<(n-1); i++)
    {
        int dif = abs(arr[i]-arr[i+1]);
        if(dif>1) 
        {
            flag = false;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}