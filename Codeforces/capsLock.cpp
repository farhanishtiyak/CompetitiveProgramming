#include<bits/stdc++.h>
using namespace std;

int main()
{
   
    string s;
    cin>>s;
    int up=0; 
    int low=0;
    int n=s.size();
    int first = int(s[0]);
    for(int i=0; i<n; i++)
    {
        if(int(s[i])>64 && int (s[i])<91) up++;
        if(int(s[i])>96 && int (s[i])<123) low++; 
    }

    //cPAS
    if(first>96&&first<123 && up==n-1)
    {
        char c=s[0]&'_';
        cout<<c;
        for(int i=1; i<n; i++) 
        {
            char ch = s[i]|' ';
            cout<<ch;
        }
        cout<<endl;
        
    }

    //CapsLock
    else if(first>64&&first<91 && up<n) cout<<s<<endl;
    //CAPSLOCK
    else if(up==n)
    {
        for(int i=0; i<n; i++) 
        {
            char ch = s[i]|' ';
            cout<<ch;
        }
        cout<<endl;
    }
    //a
    else if(first>96&&first<123 && n==1) 
    {
         char c=s[0]&'_';
         cout<<c<<endl;
    }
    else cout<<s<<endl;
}
   