// Problem link: https://codeforces.com/contest/508/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solution()
{
    string s;
    cin>>s;
    int sz = s.size();
    bool flag = false;
    int index = -1, check = s[sz-1]-'0';
    for(int i=0; i<sz; i++)
    {
        int x = s[i]-'0';
        if(x%2==0)
        {
            flag=true;
            if(x<check)
            {
                swap(s[i],s[sz-1]);
                cout<<s<<endl;
                return;
            }
            else
            {
                index =i;
            }
        }
    }
    if(flag)
    {
        swap(s[index],s[sz-1]);
        cout<<s<<endl;
    }
    else cout<<-1<<endl;
}
int main()
{
    int t=1;
    //cin >> t;
    while (t--) solution();
}

