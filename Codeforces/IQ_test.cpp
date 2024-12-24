#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e=0, o=0;
    cin>>n;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x&1==1) o++;
        else e++;
        v.push_back(x);
    }
    if(o==1)
    {
        for(int i=0; i<n; i++)
        {
            if(v[i]&1==1)
            {
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(v[i]&1==1) continue;
            else
            {
                cout<<i+1<<endl;
                return 0;
            }
        }
    }

}