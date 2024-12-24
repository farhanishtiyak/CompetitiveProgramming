#include<bits/stdc++.h>
using namespace std;

void solve()
{
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_set<char>st;
        int flag =0;
        int a=0,b=0,c=0,d=0,e=0;
        for(int i=0; i<s.size(); i++) 
        {
            if(s[i]=='T') a++;
            else if(s[i]=='i')b++;
            else if(s[i]=='m')c++;
            else if(s[i]=='u')d++;
            else if(s[i]=='r')e++;
            else flag++;
            st.insert(s[i]);
        }
        
        if(flag>0)
        {
            cout<<"NO"<<endl;
            return;
        }
        else if(st.size()==5 && a==1&&b==1&&c==1&&d==1&&e==1)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}