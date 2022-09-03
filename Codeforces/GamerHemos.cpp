// Problem Link : https://codeforces.com/problemset/problem/1592/A


#include<bits/stdc++.h>
using namespace std;

void gamerHemos()
{
    int n,k;
    cin>>n>>k;
    vector<int>v;
    for(auto i=0; i<n; i++) 
    {
        int x;
        cin>>x;
        v.push_back(x);
    } 
    sort(v.begin(),v.end());
    int x =*(v.end()-1);
    int y =*(v.end()-2);
    int ans = (k/(x+y)); 
    int difference = k-ans;
    ans = ans*2;
    if(difference==0)cout<<ans<<endl;
    else if(difference>x)cout<<(ans+2)<<endl;
    else cout<<(ans+1)<<endl;   
}
int main()
{
    int t; 
    cin>>t;
    while(t--) gamerHemos();
}

//        Time Limit Exceeded  

/*
#include<bits/stdc++.h>
using namespace std;

void gamerHemos()
{
    int n,k;
    cin>>n>>k;
    vector<int>v;
    for(auto i=0; i<n; i++) 
    {
        int x;
        cin>>x;
        v.push_back(x);
    }   
    sort(v.begin(),v.end(),greater<int>());
    int m1 = v[0];
    int m2 = v[1];
    if(k<=m1) 
    {
        cout<<1<<endl;
        return;
    }
    bool flag = true;
    int ans =0;
    while(k>0)
    {
        if(flag)
        {
            ++ans;
            k-=m1;
            flag = false;
        }
        else
        {
            ++ans;
            k-=m2;
            flag = true;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t; 
    cin>>t;
    while(t--) gamerHemos();
}

*/