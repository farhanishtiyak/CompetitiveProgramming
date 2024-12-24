// Problem link: https://codeforces.com/problemset/problem/208/A


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dubStep()
{
    string s;
    cin>>s;
    int n = s.size();
    int i=0;
    bool flag = false;
    while(i<n)
    {
        if((i+2)<n and s[i]=='W' and s[i+1]=='U' and s[i+2]=='B')
        {
            if(flag) cout<<" ";
            i+=3;
        }
        else 
        {
            cout<<s[i++];
            flag = true;
        }
    }
    cout<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
   while(t--)  dubStep();
}