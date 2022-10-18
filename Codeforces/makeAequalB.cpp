// Problem link : https://codeforces.com/contest/1736/problem/A

#include<bits/stdc++.h>
using namespace std;
 
void make_A_equal_B()
{
    
    int n;
    cin>>n;
    int arr[n];
    int brr[n];
    int Aone =0, Bone=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]==1) Aone++;
    }
    for(int i=0; i<n; i++)
    {
        cin>>brr[i];
        if(brr[i]==1) Bone++;
    }

    int diff = abs(Aone-Bone);
    int cnt =0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=brr[i]) cnt++;
    }
    if(cnt == diff) cout<<diff<<endl;
    else cout<<(diff+1)<<endl;
        
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       make_A_equal_B();
    }
}