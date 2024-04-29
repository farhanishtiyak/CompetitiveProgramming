// Problem link: 

#include <bits/stdc++.h>
using namespace std;
#define ll    long long

void maximumSubstring()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool flag = true;
    int totalOne=0, totalzero=0, one =0,zero =0, x=0,y=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1') 
        {
            totalOne++;
            one++;
            flag = true;
        }
        else 
        {
            totalzero++;
            zero++;
            flag = false;
        }
        if(flag)
        {
            x = max(x,one);
            zero =0;
        }
        else
        {
            y = max(y,zero);
            one =0;
        }

    }
    cout<<totalzero<<" "<<totalOne<<" "<<x<<" "<<y<<endl;
}
int main() 
{
    int t=1;
    cin>>t;
    while(t--) maximumSubstring();

}
