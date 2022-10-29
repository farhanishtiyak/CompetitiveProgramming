// Problem linK: https://codeforces.com/contest/1690/problem/C


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void restoringTheDurationOfTask()
{
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) cin>>brr[i];

    cout<<brr[0]-arr[0]<<" ";
    
    int maxi = brr[0];

    for(int i=1; i<n; i++)
    {
        maxi = max(maxi,arr[i]);
        cout<<brr[i]-maxi<<" ";
        maxi = brr[i];
    }
    cout<<endl;

}
int main()
{
    int t=1;
    cin>>t;
    while(t--)  restoringTheDurationOfTask();
}