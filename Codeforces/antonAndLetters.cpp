// Problem Link: https://codeforces.com/contest/443/problem/A



#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
   int t=1;
   //cin>>t;
   while(t--) 
   {
        // Problem Name: Anton and letters
        unordered_set<char> st;
       char x;
       while(x!='}')
       {
            cin>>x;
            if(x==',' or x=='}' or x=='{') continue;
            else st.insert(x);
       }
       cout<<st.size()<<endl;
   }

}