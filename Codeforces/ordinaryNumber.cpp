// Problem link: https://codeforces.com/problemset/problem/1520/B


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void ordinaryNumber()
{
    int n;
    cin>>n;
    int ans =0;
    if(n<10)
    {
        cout<<n<<endl;
        return;
    }
    string s = to_string(n);
    int len = s.size();
    ans = 9*(len-1);
    int x =1;
    for(int i=0; i<len; i++) x = x*10;
    if(n==x)
    {
        cout<<ans<<endl;
        return;
    }
    else
    {
        int  num = s[0]-'0';
        int sum =0;
        for(int i=0; i<len; i++)   sum = (sum*10)+num;
        if(sum<=n) ans = ans+num;
        else ans = ans+(num-1);
    }
    cout<<ans<<endl;


}
int main()
{
    int t=1;
    cin>>t;
   while(t--) 
   {
        ordinaryNumber();
   }
}