// Problem link: https://codeforces.com/contest/1374/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Movebrackets()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int o =0, c =0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(') o++;
        else
        {
            if(o>0) o--;
            else c++;
        }
    }

    cout<<max(o,c)<<endl;

}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  Movebrackets();
}