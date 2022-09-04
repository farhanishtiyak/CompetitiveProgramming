#include<bits/stdc++.h>
using namespace std;
#define ll    long long int;
int main()
{
    int n,d;
    cin>>n>>d;
    vector<int>arr;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(), greater<int>());
    int ans =0;
    for(int i=0; i<n; i++)
    {
        int c = d%arr[i];
        if((arr.size()-(i+1))>=c)
        {
            ans++;
            while(c--) arr.pop_back();         
        }

    }
    cout<<ans<<endl;

}