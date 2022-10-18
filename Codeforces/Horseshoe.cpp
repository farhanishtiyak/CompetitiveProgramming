// Problem Link: https://codeforces.com/problemset/problem/228/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
   int t=1;
   //cin>>t;
   while(t--) 
   {
        unordered_set<int>st;
        for(int i=0; i<4; i++)
        {
            int x;
            cin>>x;
            st.insert(x);
        }

        cout<<(4-st.size())<<endl;
   }
}