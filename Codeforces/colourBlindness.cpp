#include<bits/stdc++.h>
using namespace std;

void solution()
{
    int n;
    cin>>n;
    string st,str;
    cin>>st>>str;

    for(int i=0; i<n; i++)
    {
        if(st[i]=='G') st[i]='B';
        if(str[i]=='G') str[i]='B';
    }
    if(st.compare(str)==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--) solution();
}