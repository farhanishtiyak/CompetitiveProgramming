#include<bits/stdc++.h>

using namespace std;
void solution()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    int mx = 0;
    int cnt =0;
    for(int i=1; i<n; i++)
    {
        if(i==1)
        {
            if(arr[i]>=arr[0]) 
            {
                cnt+=2;
                mx=max(mx,cnt);
            }
            else 
            {
                cnt++;
                mx=max(mx,cnt);
            }
        }
        else
        {
            if(arr[i]>=arr[i-1]) 
            {
                cnt++;
                mx=max(mx,cnt);
            }
            else
            {
                mx=max(mx,cnt);
                cnt = 1;
            }
        }
        
    }
    cout<<mx<<endl;
}

int main()
{
    solution();
}