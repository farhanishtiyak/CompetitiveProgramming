// Problem link: https://codeforces.com/problemset/problem/427/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void policeRecruit()
{
    int n;
    cin>>n;
    int sum =0, ans =0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x>0) sum+=x;
        else
        {
            if(sum>0) sum--;
            else ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    policeRecruit();
}