#include<bits/stdc++.h>
using namespace std;

void RemovePrefix()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    unordered_set<int> st;
    
    for(auto it = n-1; it>=0; it--)
    {
        if(st.count(v[it]))
        {
            cout<<v.size()<<endl;
            return;
        }
        else
        {
            st.insert(v[it]);
            v.pop_back();
        }
    }
    cout<<0<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) RemovePrefix();
}