// Problem link: https://codeforces.com/problemset/problem/732/A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int price, change;
    cin>>price >>change;
    int p = price;

    bool flag = true;
    int ans =1;
    while(flag)
    {
        if(price%10==0)
        {
            flag = false;
        }
        else if(price%10==change) flag = false;
        else 
        { 
            ans++;
            price = price + p;
        }
    }
    cout<<ans<<endl;
}