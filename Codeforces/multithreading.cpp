// Problem link : https://codeforces.com/contest/270/problem/B

#include<bits/stdc++.h>
using namespace std;
 
void multithreading()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int cnt =0;
    for(int i=(n-1); i>0; i--)
    {
        
        if(arr[i]>arr[i-1]) 
        {
            cnt++;
            if(i==1) cnt++;
        }
        else 
        {
            cnt++;
            break;
        }
    }
    cout<<(n-cnt)<<endl;
        
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
       multithreading();
    }
}