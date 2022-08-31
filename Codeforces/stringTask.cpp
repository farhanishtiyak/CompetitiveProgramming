#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<char> v;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
        {
            continue;
        }
        else
        {
            s[i] = s[i]|' ';
            v.push_back('.');
            v.push_back(s[i]);
        }
    }

    for(auto it:v) cout<<it;
    cout<<endl;
}