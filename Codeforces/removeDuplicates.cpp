// Problem link: https://codeforces.com/problemset/problem/978/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    for(int i=(n-1); i>=0; i--)
    {
        if(mp[arr[i]]) continue;
        else 
        {
            mp[arr[i]]++;
            ans.push_back(arr[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it =(ans.end()-1); it!=ans.begin()-1; it--)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    

}