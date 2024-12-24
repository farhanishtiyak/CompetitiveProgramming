#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<string> s;
    string str;
    cin>>str;
    s.push(str);
    for(int i=1; i<=n-1; i++)
    {
        cin>>str;
        if(s.top()!=str) s.push(str);
    }
    cout<<s.size()<<endl;
   
}