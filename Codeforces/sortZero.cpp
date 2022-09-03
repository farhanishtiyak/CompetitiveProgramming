// Problem Link : https://codeforces.com/problemset/problem/1712/C

#include<bits/stdc++.h>
using namespace std;


void sortZero()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto i=0; i<n; i++) cin>>v[i];
    if(is_sorted(v.begin(),v.end()))
    {
        cout<<0<<endl;
        return;
    }
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) 
    {
        if(mp.find(v[i])==mp.end()) mp[v[i]] = i;
    }
    int violate =-1;
    for(int i=n-1; i>=1; i--)
    {
        if(v[i-1]>v[i]) 
        {
            violate = i-1;
            break;
        }
    }
    int answer = mp.size();
    set<int>st;

    for(int i=n-1; i>=violate+1; i--)
    {
        if(mp[v[i]]<=violate) 
        {
            break;
        }
         st.insert(v[i]);
    }
    answer-=st.size();
    cout<<answer<<endl;

}
int main()
{
    int t;   
    cin>>t;
    while(t--)
    sortZero();
}