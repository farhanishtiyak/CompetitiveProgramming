// Problem link: https://codeforces.com/contest/1681/problem/A

#include<bits/stdc++.h>
using namespace std;

void solution ()
{
    int n;
    cin>>n;
    vector<int>v;
    vector<int>vec;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int a = *max_element(v.begin(),v.end());
    int b = *max_element(vec.begin(),vec.end());
    if(a>b)
    {
        cout<<"Alice"<<endl<<"Alice"<<endl;
    }
    else if(b>a) cout<<"Bob"<<endl<<"Bob"<<endl;
    else cout<<"Alice"<<endl<<"Bob"<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    solution();
}