// Problem link: 

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t=1;
    //cin>>t;
   while(t--) 
   {
        string s;
        cin>>s;
        string ans = " ";
        int n = s.size();
        for(int i=0; i<n;)
        {
            if(s[i]=='.') 
            {
                ans+='0';
                i++;
            }
            else
            {
                if(s[i+1]=='.') ans+='1';
                else ans+='2';
                i+=2;
            }
        }
        cout<<ans<<endl;
   }
}