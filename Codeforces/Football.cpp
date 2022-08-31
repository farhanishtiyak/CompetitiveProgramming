//problem link : https://codeforces.com/problemset/problem/43/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_map<string,int> ans;
    for(int i=0; i<n; i++) 
    {
        string s;
        cin>>s;
        ans[s]++;
    }
    int maximum = INT_MIN;
    for(auto value = ans.begin(); value !=ans.end(); ++value)
    {
        maximum=max(maximum,value->second);
    }
    
    for(auto value = ans.begin(); value !=ans.end(); ++value)
    {
        if(value->second==maximum) cout<<value->first<<endl;
    }
    
}