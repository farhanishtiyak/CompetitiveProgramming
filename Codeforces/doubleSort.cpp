// Problem Link : https://codeforces.com/contest/1681/problem/C

#include<bits/stdc++.h>
using namespace std;
void doubleSort()
{
    int n;
        cin>>n;
        vector<int>v;
        vector<int>vv;
        vector<pair<int,int>>ans;
        for(int i=0; i<n; i++) 
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        for(int i=0; i<n; i++) 
        {
            int x;
            cin>>x;
            vv.push_back(x);
        }

        for(int i=0; i<n-1; i++)
        {
            if(v[i]<v[i+1]&&vv[i]<vv[i+1]) continue;
            else if(v[i]>v[i+1]&&vv[i]>vv[i+1]) 
            {
                swap(v[i],v[i+1]);
                swap(vv[i],vv[i+1]);
                ans.push_back({i+1,i+2});

            }
            else 
            {
                cout<<-1<<endl;
                return;
            }
        }
        cout<<ans.size()<<endl;
        for(auto it=ans.begin(); it!=ans.end(); it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        doubleSort();
    }
}