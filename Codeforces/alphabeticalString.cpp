// Problem Link: https://codeforces.com/contest/1547/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void alphabeticalString()
{
    string s;
    cin>>s;
    int n = s.size()-1;
    int x,y;
    bool a_Present = false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='a') 
        {
            x = i+1;
            y = i-1;    
            a_Present = true;
            break;
        }
    }

    if(!a_Present)
    {
        cout<<"NO"<<endl;
        return;
    }

    bool flag = true;
    int cnt =1;
    char ch = 'b';
    while(cnt <=n)
    {
        if(s[x]==ch)
        {
            ch++;
            x+=1;
        }
        else if(s[y]==ch)
        {
            ch++;
            y-=1;
        }
        else
        {
            flag = false;
            break;
        }
        cnt++;

    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--) 
   {
        alphabeticalString();
   }
}