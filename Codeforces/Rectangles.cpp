// Problem link: https://codeforces.com/gym/101020/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rectangles()
{
    int n;
    cin>>n;
    set<pair<int,int>>st;
    for(int i=1; i<=n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a++;
        for(int i=a; i<=b; i++)
        {
            for(int j=1; j<=c; j++) st.insert({i,j});
        }
    }

    cout<<st.size()<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--) Rectangles();
}